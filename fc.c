#include <stdio.h>

#include <stdio.h>

float celsiusParaFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main() {
    float celsius, fahrenheit;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = celsiusParaFahrenheit(celsius);

    printf("A temperatura em Fahrenheit e: %.2f\n", fahrenheit);

    return 0;
}

