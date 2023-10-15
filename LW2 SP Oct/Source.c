#include <stdio.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_ALPHABET 256  // ������ ����� ������� ��� ��������
#define MAX_LENGTH 100

struct Transition {
	int fromState;
	char symbol;
	int toState;
};

int isAccepted(char* w0, struct Transition transitions[MAX_STATES][MAX_ALPHABET], int initialState, int finalState) {
	int currentState = initialState;

	// ������ ����� ����� ������ ����� � �������� ������� � �������
	for (int i = 0; i < strlen(w0); ++i) {
		char symbol = w0[i];

		// ������ ��������� �������
		int found = 0;
		for (int j = 0; j < MAX_ALPHABET; ++j) {
			if (transitions[currentState][j].symbol == symbol) {
				currentState = transitions[currentState][j].toState;
				found = 1;
				break;
			}
		}

		// ���� �� �������� ���������� ��������, ����� �� �����������
		if (!found) {
			return 0;
		}
	}

	// ��������, �� ��������� �� � ���������� ����
	return currentState == finalState;
}

int main() {
	int numStates, numTransitions;
	int initialState, finalState;
	char filename[50]; // ����� �����

	// ����� ����������� ��� ��'� �����
	printf("Enter the filename with the automaton description: ");
	scanf_s("%s", filename, sizeof(filename));

	FILE* file;
	if (fopen_s(&file, filename, "r") != 0) {
		perror("Error opening file");
		return 1;
	}

	// ���������� ������� ����� � ��������
	fscanf_s(file, "%d %d", &numStates, &numTransitions);

	// ���������� ����������� � �������� �����
	fscanf_s(file, "%d %d", &initialState, &finalState);

	// ����������� ������ ��������
	struct Transition transitions[MAX_STATES][MAX_ALPHABET] = { 0 };

	// ���������� ��������
	for (int i = 0; i < numTransitions; ++i) {
		int fromState, toState;
		char symbol;
		fscanf_s(file, "%d %c %d", &fromState, &symbol, sizeof(symbol), &toState);
		transitions[fromState][symbol].fromState = fromState;
		transitions[fromState][symbol].symbol = symbol;
		transitions[fromState][symbol].toState = toState;
	}

	fclose(file); // �������� �����

	char w0[MAX_LENGTH];

	// �������� w0
	printf("Enter the word w0: ");
	scanf_s("%s", w0, sizeof(w0));

	// �������� �� ��������� ����������
	if (isAccepted(w0, transitions, initialState, finalState)) {
		printf("The word w = %s is accepted by the finite automaton.\n", w0);
	}
	else {
		printf("The word w = %s is not accepted by the finite automaton.\n", w0);
	}

	return 0;
}
