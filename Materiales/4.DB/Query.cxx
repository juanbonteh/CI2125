///
/// Query.cxx - archiv para completar los ejercicios del examen
///
/// Aqui deben realizar sus tareas de algebra relacional
/// La salida de cada query debe imprimir la tabla del resultado
/// .. y retornar EXIT_SUCCESS, de ser exitosa, o EXIT_FAILURE en caso de falla.

#include "Query.h"
// .. y otros encabezados que van a ser necesarios
#include "Asignatura.h"
#include "Calificacion.h"
#include "Estudiante.h"

#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::tuple;
using std::unordered_map;
using std::unordered_set;
using std::vector;

namespace {

unordered_map<string, int> build_uc_index() {
    unordered_map<string, int> uc_index;
    for (auto asignatura : Asignatura::tabla()) {
        uc_index[asignatura.codigo().str()] = asignatura.uc();
    }
    return uc_index;
}

} // namespace

int Query::q0() {
    const string carrera_electronica = "0600";
    const int target_year = 2044;

    unordered_set<string> carnets_electronica;
    for (const auto &estudiante : Estudiante::tabla()) {
        if (estudiante.carrera().str() == carrera_electronica) {
            carnets_electronica.insert(estudiante.carnet().str());
        }
    }

    if (carnets_electronica.empty()) {
        fprintf(stderr, "No hay estudiantes de Ingeniería Electrónica registrados\n");
        return EXIT_FAILURE;
    }

    const auto uc_index = build_uc_index();
    double weighted_sum = 0.0;
    int total_uc = 0;

    for (const auto &calificacion : Calificacion::tabla()) {
        if (calificacion.year() != target_year) {
            continue;
        }
        if (carnets_electronica.find(calificacion.carnet().str()) == carnets_electronica.end()) {
            continue;
        }
        auto it = uc_index.find(calificacion.asignatura().str());
        if (it == uc_index.end()) {
            continue;
        }
        int uc = it->second;
        weighted_sum += static_cast<double>(calificacion.nota()) * static_cast<double>(uc);
        total_uc += uc;
    }

    if (total_uc == 0) {
        fprintf(stderr, "No hay calificaciones para Ingeniería Electrónica en %d\n", target_year);
        return EXIT_FAILURE;
    }

    float indice_promedio = static_cast<float>(weighted_sum / static_cast<double>(total_uc));
    fprintf(stdout, "Índice académico promedio Ingeniería Electrónica %d: %.4f\n", target_year, indice_promedio);
    return EXIT_SUCCESS;
}

int Query::q1() {
    const unordered_set<string> carreras_objetivo = {"0800", "0600"};
    const int target_year = 2050;
    int conteo = 0;

    for (const auto &estudiante : Estudiante::tabla()) {
        if (!estudiante.graduado()) {
            continue;
        }
        if (carreras_objetivo.find(estudiante.carrera().str()) == carreras_objetivo.end()) {
            continue;
        }

        bool tiene_historial = false;
        for (const auto &calificacion : Calificacion::tabla()) {
            if (calificacion.carnet().str() != estudiante.carnet().str()) {
                continue;
            }
            if (calificacion.year() <= target_year) {
                tiene_historial = true;
                break;
            }
        }

        if (tiene_historial) {
            ++conteo;
        }
    }

    fprintf(stdout, "Graduados de Computación y Electrónica hasta %d: %d\n", target_year, conteo);
    return EXIT_SUCCESS;
}

int Query::q2() {
    const string departamento_ci = "CI";
    vector<Asignatura> resultado;

    for (auto asignatura : Asignatura::tabla()) {
        if (asignatura.departamento().str() == departamento_ci) {
            resultado.push_back(asignatura);
        }
    }

    fprintf(stdout, "Asignaturas del departamento de Computación (%zu):\n", resultado.size());
    for (const auto &asignatura : resultado) {
        fprintf(stdout, "%s\n", asignatura.str().c_str());
    }

    return EXIT_SUCCESS;
}

int Query::q3() {
    const string matematicas_vii = "MA3111";
    const string fisica_i = "FS1111";

    unordered_set<string> cursaron_mate_vii;
    unordered_set<string> pasaron_fisica_i;

    for (const auto &calificacion : Calificacion::tabla()) {
        string carnet = calificacion.carnet().str();
        if (calificacion.asignatura().str() == matematicas_vii) {
            cursaron_mate_vii.insert(carnet);
        }
        if (calificacion.asignatura().str() == fisica_i && calificacion.nota() >= 4) {
            pasaron_fisica_i.insert(carnet);
        }
    }

    vector<Estudiante> resultado;
    for (const auto &estudiante : Estudiante::tabla()) {
        string carnet = estudiante.carnet().str();
        if (!estudiante.activo()) {
            continue;
        }
        if (cursaron_mate_vii.find(carnet) != cursaron_mate_vii.end() &&
            pasaron_fisica_i.find(carnet) != pasaron_fisica_i.end()) {
            resultado.push_back(estudiante);
        }
    }

    fprintf(stdout, "Estudiantes activos que cursaron Matemáticas VII y aprobaron Física I (%zu):\n", resultado.size());
    for (const auto &estudiante : resultado) {
        fprintf(stdout, "%s\n", estudiante.str().c_str());
    }

    return EXIT_SUCCESS;
}

int Query::q4() {
    const string carrera_electronica = "0600";
    const string matematicas_iv = "MA2115";
    const int max_year = 2046;

    const auto uc_index = build_uc_index();

    // Filtrar estudiantes activos de electrónica.
    unordered_set<string> activos_electronica;
    for (const auto &estudiante : Estudiante::tabla()) {
        if (estudiante.activo() && estudiante.carrera().str() == carrera_electronica) {
            activos_electronica.insert(estudiante.carnet().str());
        }
    }

    // Registrar quienes cursaron Matemáticas IV antes o durante el año objetivo.
    unordered_set<string> cursaron_mat_iv;
    unordered_map<string, int> uc_aprobadas;
    for (const auto &calificacion : Calificacion::tabla()) {
        string carnet = calificacion.carnet().str();
        if (activos_electronica.find(carnet) == activos_electronica.end()) {
            continue;
        }
        if (calificacion.asignatura().str() == matematicas_iv && calificacion.year() <= max_year) {
            cursaron_mat_iv.insert(carnet);
        }
        if (calificacion.year() > max_year || calificacion.nota() < 4) {
            continue;
        }
        auto it = uc_index.find(calificacion.asignatura().str());
        if (it == uc_index.end()) {
            continue;
        }
        uc_aprobadas[carnet] += it->second;
    }

    vector<tuple<string, int>> resultado;
    for (const auto &carnet : cursaron_mat_iv) {
        int uc = 0;
        auto it = uc_aprobadas.find(carnet);
        if (it != uc_aprobadas.end()) {
            uc = it->second;
        }
        resultado.emplace_back(carnet, uc);
    }

    fprintf(stdout,
            "UC aprobadas por estudiantes activos de Ing. Electrónica hasta %d (que cursaron Matemáticas IV):\n",
            max_year);
    for (const auto &entrada : resultado) {
        fprintf(stdout, "(%s, %d)\n", std::get<0>(entrada).c_str(), std::get<1>(entrada));
    }

    return EXIT_SUCCESS;
}
