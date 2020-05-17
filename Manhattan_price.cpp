/* Остров Манхэттен был приобретён поселенцами за $24 в 1826 г. 
Каково было бы в настоящее время состояние их счёта, 
если бы эти 24 доллара были помещены тогда в банк под 6% годового дохода?*/

#include <iostream>
#include <iomanip>  // чтобы задать точность для вывода длинных чисел

/* глобальные константы - зло, но тут программа небольшая, 
и они будут использоваться в двух функциях, иначе пришлось создавать бы их в main
и передавать в обе функции, где их прописывать как параметры, а это ужасно удлинняет всё */
const float initial_deposit       { 24.0f };
const float percent_of_deposit    { 6.0f };
const unsigned short first_year   { 1826 };
const unsigned short current_year { 2020 };

// вычисляет текущее состояние депозита, если проценты считаются только от начальной суммы вклада
float current_deposit()
{
    float deposit{ initial_deposit };
    // каждый год депозит увеличивается на 6% от начального вклада
    deposit += (initial_deposit * percent_of_deposit / 100) * (current_year - first_year);
    return deposit;
}

// вычисляет текущее состояние депозита, если проценты начисляются с индексацией
float current_deposit_with_indexation()
{
    float deposit{ initial_deposit };
    // каждый год депозит увеличивается на 6% от текущего остатка (вместе с накопленными процентами)
    for (unsigned short year = (first_year + 1); year <= current_year; year++)
        deposit += deposit * percent_of_deposit / 100;
    return deposit;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    std::cout << "Остров Манхэттен был приобретён поселенцами за 24$ в 1826 г.\n"
              << "Программа считает, каково было бы в настоящее время состояние счёта,\n"
              << "если бы эти 24$ были помещены тогда в банк под 6% годового дохода\n" << std::endl;
    std::cout << "Состояние счёта, если проценты начислялись без индексации: " << current_deposit() << std::endl;
    std::cout << "Состояние счёта, если проценты начислялись c индексацией: " << std::setprecision(9) << current_deposit_with_indexation() << std::endl;
    return 0;
}