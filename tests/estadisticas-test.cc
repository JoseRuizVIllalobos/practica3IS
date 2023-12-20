#include <gtest/gtest.h>
#include "actividad.h"
#include "estadisticas.h"

// Test case for Estadisticas class
TEST(EstadisticasTest, EstadisticasTest1) {
    // Crear una actividad para utilizar en las pruebas
    Actividad actividad(1, 20231231, 20230101, 60, 100, "Nombre", "Tematica", "Descripcion", "Ubicacion", "Titulo", 10.0, ActividadStatus::Pendiente);
    
    Estadisticas estadisticas(50, 30, 500.0, 4.5);

    // Probar la función setInscripciones
    estadisticas.setInscripciones(60);
    EXPECT_EQ(60, estadisticas.getInscripciones());

    // Probar la función setAsistencia
    estadisticas.setAsistencia(40);
    EXPECT_EQ(40, estadisticas.getAsistencia());

    // Probar la función addRecaudacion
    estadisticas.addRecaudacion(actividad);
    EXPECT_EQ(60 * 10.0, estadisticas.getRecaudacionTotal());

    // Probar la función getPorcentajeAsistencia
    EXPECT_NEAR(0, estadisticas.getPorcentajeAsistencia(),0.01);


}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}