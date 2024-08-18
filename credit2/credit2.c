#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
        // Solicitar número de cartão de crédito ao usuário
        long card_number;
        do
        {
            card_number = get_long("Número do Cartão: ");
        }
        while (card_number <= 0);

        // Verificar se o número de cartão é válido
        int digit_count = 0;
        long temp = card_number;
        while (temp > 0)
        {
            temp /= 10;
            digit_count++;
        }

        if (digit_count != 13 && digit_count != 15 && digit_count != 16)
        {
            printf("INVALID\n");
            continue; // Volta para o início do loop
        }

        // Verificar o tipo de cartão
        int digits[digit_count];
        temp = card_number;
        for (int i = 0; i < digit_count; i++)
        {
            digits[i] = temp % 10;
            temp /= 10;
        }

        int sum = 0;
        for (int i = 1; i < digit_count; i += 2)
        {
            int doubled = digits[i] * 2;
            sum += doubled % 10 + doubled / 10;
        }

        for (int i = 0; i < digit_count; i += 2)
        {
            sum += digits[i];
        }

        if (sum % 10 == 0)
        {
            // Verificar o tipo de cartão com base nos dígitos iniciais
            if (digit_count == 15 &&
                (digits[digit_count - 1] == 3 && (digits[digit_count - 2] == 4 || digits[digit_count - 2] == 7)))
            {
                printf("AMEX\n");
            }
            else if (digit_count == 16 &&
                     (digits[digit_count - 1] == 5 && (digits[digit_count - 2] >= 1 && digits[digit_count - 2] <= 5)))
            {
                printf("MASTERCARD\n");
            }
            else if ((digit_count == 13 || digit_count == 16) && digits[digit_count - 1] == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    while (get_char("Deseja verificar outro número? (s/n): ") == 's');

    return 0;
}
