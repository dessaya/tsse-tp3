#include "unity.h"
#include "leds.h"

static uint16_t leds = 0xffff;

void setUp() {
    Leds_Create(&leds);
}

void tearDown() {}

// Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreate() {
    static uint16_t leds = 0xffff;
    Leds_Create(&leds);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

// Se puede prender un LED individual.
void test_IndividualLedOn() {
    const int led = 3;
    Leds_On(led);
    TEST_ASSERT_EQUAL_HEX16(1 << (led - 1), leds);
}

// Se puede apagar un LED individual.
void test_IndividualLedOff() {
    const int led = 3;
    Leds_On(led);
    Leds_Off(led);
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

// Se pueden prender y apagar múltiples LED’s.
void test_MultipleOnOff() {
    Leds_On(2);
    Leds_On(5);
    Leds_Off(2);
    TEST_ASSERT_EQUAL_HEX16(1 << (5 - 1), leds);
}

// Se pueden prender todos los LEDs de una vez.
void test_AllOn() {
    Leds_AllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff, leds);
}

// Se pueden apagar todos los LEDs de una vez.
void test_AllOff() {
    Leds_AllOn();
    Leds_AllOff();
    TEST_ASSERT_EQUAL_HEX16(0x0, leds);
}

// Se puede consultar el estado de un LED.
void test_IsOn() {
    const int led = 2;
    TEST_ASSERT_EQUAL_INT(false, Leds_IsOn(led));
    Leds_On(led);
    TEST_ASSERT_EQUAL_INT(true, Leds_IsOn(led));
}

// Revisar limites de los parametros.
void test_On1() {
    const int led = 1;
    Leds_On(led);
    TEST_ASSERT_EQUAL_HEX16(1 << (led - 1), leds);
}

void test_On16() {
    const int led = 16;
    Leds_On(led);
    TEST_ASSERT_EQUAL_HEX16(1 << (led - 1), leds);
}

void test_Off1() {
    const int led = 1;
    Leds_AllOn();
    Leds_Off(led);
    TEST_ASSERT_EQUAL_HEX16(~(1 << (led - 1)), leds);
}

void test_Off16() {
    const int led = 16;
    Leds_AllOn();
    Leds_Off(led);
    TEST_ASSERT_EQUAL_HEX16(~(1 << (led - 1)), leds);
}

void test_IsOn1() {
    const int led = 1;
    TEST_ASSERT_EQUAL_INT(false, Leds_IsOn(led));
    Leds_On(led);
    TEST_ASSERT_EQUAL_INT(true, Leds_IsOn(led));
}

void test_IsOn16() {
    const int led = 16;
    TEST_ASSERT_EQUAL_INT(false, Leds_IsOn(led));
    Leds_On(led);
    TEST_ASSERT_EQUAL_INT(true, Leds_IsOn(led));
}

// Revisar parámetros fuera de los limites.
void test_On0() {
    const int led = 0;
    Leds_On(led);
    TEST_ASSERT_EQUAL_HEX16(0x0, leds);
}

void test_On17() {
    const int led = 17;
    Leds_On(led);
    TEST_ASSERT_EQUAL_HEX16(0x0, leds);
}

void test_Off0() {
    const int led = 0;
    Leds_AllOn();
    Leds_Off(led);
    TEST_ASSERT_EQUAL_HEX16(0xffff, leds);
}

void test_Off17() {
    const int led = 17;
    Leds_AllOn();
    Leds_Off(led);
    TEST_ASSERT_EQUAL_HEX16(0xffff, leds);
}

void test_IsOn0() {
    const int led = 0;
    TEST_ASSERT_EQUAL_INT(false, Leds_IsOn(led));
    Leds_On(led);
    TEST_ASSERT_EQUAL_INT(false, Leds_IsOn(led));
}

void test_IsOn17() {
    const int led = 17;
    TEST_ASSERT_EQUAL_INT(false, Leds_IsOn(led));
    Leds_On(led);
    TEST_ASSERT_EQUAL_INT(false, Leds_IsOn(led));
}

