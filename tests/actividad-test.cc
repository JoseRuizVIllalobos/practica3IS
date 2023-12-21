#include <gtest/gtest.h>
#include <actividad.hpp>
// Test case for Actividad class
TEST(ActividadTest, ConstructorTest) {
    // Crear una instancia de Actividad
    Actividad actividad(1, 20231231, 20230101, 60, 100, "Nombre", "Tematica", "Descripcion", "Ubicacion", "Titulo", 10.0, ActividadStatus::PENDIENTE);

    // Verificar que los valores se inicializan correctamente
    EXPECT_EQ(1, actividad.getID());
    //EXPECT_EQ(20231231, actividad.getFechaFin());
    //EXPECT_EQ(20230101, actividad.getFechaInicio());
    EXPECT_EQ(60, actividad.getDuracion());
    EXPECT_EQ(100, actividad.getAforo());
    EXPECT_EQ("Nombre", actividad.getNombre());
    EXPECT_EQ("Tematica", actividad.getTematica());
    EXPECT_EQ("Descripcion", actividad.getDescripcion());
    EXPECT_EQ("Ubicacion", actividad.getUbicacion());
    EXPECT_EQ("Titulo", actividad.getTitulo());
    EXPECT_FLOAT_EQ(10.0, actividad.getPrecio());
    EXPECT_EQ(ActividadStatus::PENDIENTE, actividad.getEstado());
}

TEST(ActividadTest, SettersAndGettersTest) {
    // Crear una instancia de Actividad
    Actividad actividad(1, 20231231, 20230101, 60, 100, "Nombre", "Tematica", "Descripcion", "Ubicacion", "Titulo", 10.0, ActividadStatus::PENDIENTE);

    // Probar setters
    actividad.setID(2);
    //actividad.setFechaFin(20231231);
    //actividad.setFechaInicio(20230101);
    actividad.setDuracionMinutos(90);
    actividad.setAforo(150);
    actividad.setNombre("NuevoNombre");
    actividad.setTematica("NuevaTematica");
    actividad.setDescripcion("NuevaDescripcion");
    actividad.setUbicacion("NuevaUbicacion");
    actividad.setTitulo("NuevoTitulo");
    actividad.setPrecio(15.0);
    actividad.setPonentes("NuevoPonente");
    actividad.deletePonentes("NuevoPonente");
    actividad.setEstado(ActividadStatus::PASADA);

    // Probar getters
    EXPECT_EQ(2, actividad.getID());
    //EXPECT_EQ(20231231, actividad.getFechaFin());
    //EXPECT_EQ(20230101, actividad.getFechaInicio());
    EXPECT_EQ(90, actividad.getDuracion());
    EXPECT_EQ(150, actividad.getAforo());
    EXPECT_EQ("NuevoNombre", actividad.getNombre());
    EXPECT_EQ("NuevaTematica", actividad.getTematica());
    EXPECT_EQ("NuevaDescripcion", actividad.getDescripcion());
    EXPECT_EQ("NuevaUbicacion", actividad.getUbicacion());
    EXPECT_EQ("NuevoTitulo", actividad.getTitulo());
    EXPECT_FLOAT_EQ(15.0, actividad.getPrecio());
    EXPECT_EQ(ActividadStatus::PASADA, actividad.getEstado());
}

// Otros casos de prueba para setters y getters específicos si es necesario
// ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
