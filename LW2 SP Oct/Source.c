#include <stdio.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_ALPHABET 256  // Змінено розмір алфавіту для кирилиці
#define MAX_LENGTH 100

struct Transition {
	int fromState;
	char symbol;
	int toState;
};

int isAccepted(char* w0, struct Transition transitions[MAX_STATES][MAX_ALPHABET], int initialState, int finalState) {
	int currentState = initialState;

	// Пройти через кожен символ слова і виконати перехід в автоматі
	for (int i = 0; i < strlen(w0); ++i) {
		char symbol = w0[i];

		// Знайти відповідний перехід
		int found = 0;
		for (int j = 0; j < MAX_ALPHABET; ++j) {
			if (transitions[currentState][j].symbol == symbol) {
				currentState = transitions[currentState][j].toState;
				found = 1;
				break;
			}
		}

		// Якщо не знайдено відповідного переходу, слово не допускається
		if (!found) {
			return 0;
		}
	}

	// Перевірка, чи завершили ми в фінальному стані
	return currentState == finalState;
}

int main() {
	int numStates, numTransitions;
	int initialState, finalState;
	char filename[50]; // Назва файлу

	// Запит користувача про ім'я файлу
	printf("Enter the filename with the automaton description: ");
	scanf_s("%s", filename, sizeof(filename));

	FILE* file;
	if (fopen_s(&file, filename, "r") != 0) {
		perror("Error opening file");
		return 1;
	}

	// Зчитування кількості станів і переходів
	fscanf_s(file, "%d %d", &numStates, &numTransitions);

	// Зчитування початкового і кінцевого станів
	fscanf_s(file, "%d %d", &initialState, &finalState);

	// Ініціалізація масиву переходів
	struct Transition transitions[MAX_STATES][MAX_ALPHABET] = { 0 };

	// Зчитування переходів
	for (int i = 0; i < numTransitions; ++i) {
		int fromState, toState;
		char symbol;
		fscanf_s(file, "%d %c %d", &fromState, &symbol, sizeof(symbol), &toState);
		transitions[fromState][symbol].fromState = fromState;
		transitions[fromState][symbol].symbol = symbol;
		transitions[fromState][symbol].toState = toState;
	}

	fclose(file); // Закриття файлу

	char w0[MAX_LENGTH];

	// Введення w0
	printf("Enter the word w0: ");
	scanf_s("%s", w0, sizeof(w0));

	// Перевірка та виведення результату
	if (isAccepted(w0, transitions, initialState, finalState)) {
		printf("The word w = %s is accepted by the finite automaton.\n", w0);
	}
	else {
		printf("The word w = %s is not accepted by the finite automaton.\n", w0);
	}

	return 0;
}
