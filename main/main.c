#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

// SENSOR PINS
#define L_sensor 0  // Left sensor
#define M_sensor 1  // Middle sensor
#define R_sensor 2  // Right sensor

// MOTOR PINS
#define ML_Ctrl PD2
#define MR_Ctrl PD4
#define ML_PWM  PD5
#define MR_PWM  PD6

// MOTOR PARAMETERS
#define MOTOR_PWM_TIMER_TOP 255
#define MOTOR_MINIMUM_SPEED 0
#define MOTOR_MAXIMUM_SPEED 70

#define MAX_LEFT 80
#define MAX_RIGHT 70

#define forward 0
#define backward 1

#define motor_speed 150



// SENSOR THRESHOLDS
// Threshold values used for line detection
// Adjusted individually for each sensor
#define THRESHOLD_left   655
#define THRESHOLD_middle 655
#define THRESHOLD_right  602

// Thresholds for hard turns
#define THRESHOLD_rightO 608
#define THRESHOLD_leftO  500

// ADC INITIALIZATION
void ADC_init() {
    ADMUX = (1 << REFS0);
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
}

// READ ADC CHANNEL
uint16_t readADC(uint8_t channel) {

    // Select ADC channel
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

    // Start conversion
    ADCSRA |= (1 << ADSC);

    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));

    return ADC;
}


// MOTOR INITIALIZATION
void setup(void) {

    // Configure motor control pins as outputs
    DDRD |= (1 << ML_Ctrl) | (1 << MR_Ctrl);

    // Configure PWM pins as outputs
    DDRD |= (1 << ML_PWM) | (1 << MR_PWM);

    // Configure Timer0 for PWM operation
    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << COM0B1);

    // Fast PWM mode
    TCCR0A |= (1 << WGM00) | (1 << WGM01);

    // Prescaler = 64
    TCCR0B |= (1 << CS01) | (1 << CS00);

    // Initial motor speed
    OCR0A = 0;
    OCR0B = 0;
}

// SET MOTOR DIRECTION
void setMotorDirection(int motorDirection) {

    if (motorDirection) {

        // Reverse direction
        PORTD |= (1 << ML_Ctrl) | (1 << MR_Ctrl);

    } else {

        // Forward direction
        PORTD &= ~((1 << ML_Ctrl) | (1 << MR_Ctrl));
    }
}


// SET MOTOR SPEED
void motorSpeed(int leftSpeed, int rightSpeed) {

    OCR0B = ((leftSpeed * MOTOR_PWM_TIMER_TOP) / 100);
    OCR0A = ((rightSpeed * MOTOR_PWM_TIMER_TOP) / 100);
}
