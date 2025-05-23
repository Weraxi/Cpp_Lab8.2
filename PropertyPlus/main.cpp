#include "Ijsonio.h"
#include "Owner.h"

void processTaxFiles(const string& inputFile, const string& outputFile);
void saveToFile(const json& j, const string& filename);

int main() {
    setlocale(LC_ALL, "");
    string inputFile, outputFile;

    cout << "������� ��� �������� JSON-�����: ";
    getline(cin, inputFile);

    cout << "������� ��� ��������� JSON-�����: ";
    getline(cin, outputFile);

    processTaxFiles(inputFile, outputFile);

    return 0;
}

void saveToFile(const json& j, const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        throw runtime_error("���������� ������� ����");
    }

    out << setw(4) << j << endl;
    out.close();
}

// ������ �������������:
void processTaxFiles(const string& inputFile, const string& outputFile) {
    try {
        ifstream fin(inputFile);
        if (!fin.is_open()) {
            throw runtime_error("���������� ������� ����");
        }

        json inputJson;
        fin >> inputJson;
        fin.close();

        Owner owner;
        owner.fromJson(inputJson);

        json outputJson = owner.toJson();
        saveToFile(outputJson, outputFile);

        cout << "�������. ��������� ������� � " << outputFile << endl;
    }
    catch (const exception& e) {
        clog << "������: " << e.what() << endl;
    }
}