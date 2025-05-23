#include "Ijsonio.h"
#include "Owner.h"

void processTaxFiles(const string& inputFile, const string& outputFile);
void saveToFile(const json& j, const string& filename);

int main() {
    setlocale(LC_ALL, "");
    string inputFile, outputFile;

    cout << "Введите имя входного JSON-файла: ";
    getline(cin, inputFile);

    cout << "Введите имя выходного JSON-файла: ";
    getline(cin, outputFile);

    processTaxFiles(inputFile, outputFile);

    return 0;
}

void saveToFile(const json& j, const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        throw runtime_error("Невозможно открыть файл");
    }

    out << setw(4) << j << endl;
    out.close();
}

// Пример использования:
void processTaxFiles(const string& inputFile, const string& outputFile) {
    try {
        ifstream fin(inputFile);
        if (!fin.is_open()) {
            throw runtime_error("Невозможно открыть файл");
        }

        json inputJson;
        fin >> inputJson;
        fin.close();

        Owner owner;
        owner.fromJson(inputJson);

        json outputJson = owner.toJson();
        saveToFile(outputJson, outputFile);

        cout << "Успешно. Результат сохранён в " << outputFile << endl;
    }
    catch (const exception& e) {
        clog << "Ошибка: " << e.what() << endl;
    }
}