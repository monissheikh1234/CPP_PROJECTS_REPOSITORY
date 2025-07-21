#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Resume {
private:
    string name, email, phone;
    string objective;
    vector<string> education;
    vector<string> skills;
    vector<string> experience;

    string getCurrentTimestamp() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", ltm);
        return string(timestamp);
    }

public:
    void inputDetails() {
        cin.ignore();
        cout << "Enter Full Name: ";
        getline(cin, name);

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Career Objective: ";
        getline(cin, objective);

        int n;

        cout << "\nEnter number of Education entries: "; cin >> n; cin.ignore();
        for (int i = 0; i < n; ++i) {
            string edu;
            cout << "  Education #" << i + 1 << ": ";
            getline(cin, edu);
            education.push_back(edu);
        }

        cout << "\nEnter number of Skills: "; cin >> n; cin.ignore();
        for (int i = 0; i < n; ++i) {
            string skill;
            cout << "  Skill #" << i + 1 << ": ";
            getline(cin, skill);
            skills.push_back(skill);
        }

        cout << "\nEnter number of Work Experience entries: "; cin >> n; cin.ignore();
        for (int i = 0; i < n; ++i) {
            string exp;
            cout << "  Experience #" << i + 1 << ": ";
            getline(cin, exp);
            experience.push_back(exp);
        }
    }

    void generateResumeFile() {
        string filename = "resume_" + getCurrentTimestamp() + ".txt";
        ofstream out(filename);
        if (!out.is_open()) {
            cout << "Error: Unable to create file." << endl;
            return;
        }

        out << "==============================\n";
        out << "         RESUME\n";
        out << "==============================\n";
        out << "Name: " << name << "\n";
        out << "Email: " << email << "\n";
        out << "Phone: " << phone << "\n\n";

        out << "Objective:\n" << objective << "\n\n";

        out << "Education:\n";
        for (auto &e : education) out << "- " << e << "\n";
        out << "\nSkills:\n";
        for (auto &s : skills) out << "- " << s << "\n";
        out << "\nExperience:\n";
        for (auto &x : experience) out << "- " << x << "\n";

        out << "\n==============================\n";

        out.close();
        cout << "\nResume successfully saved to: " << filename << endl;
    }
};

int main() {
    Resume r;
    // cout << "\n🧾 Resume Builder\n-------------------------" << endl;
    cout << "\n=== Resume Builder ===\n-------------------------" << endl;

    r.inputDetails();
    r.generateResumeFile();
    return 0;
}
