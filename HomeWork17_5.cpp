#include <iostream>
#include <vector>
#include <string>
#include <windows.h>



int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string text; // Введенный текст
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);
    const std::string separators{ " ,;:.\"!?'*\n" };     // виды разделителей  слов
    std::vector<std::string> words;                      // Создаем вектор для хранения слов
    size_t start{ text.find_first_not_of(separators) };  // начальный индекс первого слова
    while (start != std::string::npos)                   // проходим циклом , пока в строке не окажется других символов, кроме separators
    {
        size_t end = text.find_first_of(separators, start + 1); // находим, где кончается слово
        if (end == std::string::npos)                           // если не найден ни один из символов-разделителей
            end = text.length();                                // устанавливаем переменную end на конец текста
        words.push_back(text.substr(start, end - start));       // добавляем в вектор слово
        start = text.find_first_not_of(separators, end + 1);    // находим начальный индекс следующего слова и переустанавливаем start
    }
    
    std::cout << "\nВ данном тексте " << words.size() << " слов(а):" << std::endl;   
    
    



}

