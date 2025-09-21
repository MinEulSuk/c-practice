#include <iostream>
#include <vector>
#include <chrono>
#include <random>

// ����� ����ϴ� �Լ� (��� Ȯ�ο�)
void PrintMatrix(const std::vector<std::vector<double>>& matrix) {
    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // ---- ���� �� ----
    const int N = 1024; // ��� ũ��

    // ---- ��� ���� �� �ʱ�ȭ ----
    std::vector<std::vector<double>> A(N, std::vector<double>(N));
    std::vector<std::vector<double>> B(N, std::vector<double>(N));
    std::vector<std::vector<double>> C(N, std::vector<double>(N, 0.0));

    // ������ ���ڷ� ��� ä���
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 10.0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = dis(gen);
            B[i][j] = dis(gen);
        }
    }

    std::cout << N << "x" << N << " ��� ���� ����..." << std::endl;

    // ---- �ð� ���� ���� ----
    auto start = std::chrono::high_resolution_clock::now();

    //---- �ٽ� �˰���: 3�� �ݺ��� ----
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // ---- �ð� ���� ���� ----
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    // ---- ��� ��� ----
    std::cout << "��� �Ϸ�!" << std::endl;
    std::cout << "��� ����� �Ϻ�:" << std::endl;
    PrintMatrix(C); // ����� �� ���Դ��� �Ϻθ� Ȯ��
    std::cout << "�� ���� �ð�: " << diff.count() << " ��" << std::endl;

    return 0;
}