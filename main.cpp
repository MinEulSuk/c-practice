#include <iostream>
#include <vector>
#include <chrono>
#include <random>

// 행렬을 출력하는 함수 (결과 확인용)
void PrintMatrix(const std::vector<std::vector<double>>& matrix) {
    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // ---- 설정 값 ----
    const int N = 1024; // 행렬 크기

    // ---- 행렬 생성 및 초기화 ----
    std::vector<std::vector<double>> A(N, std::vector<double>(N));
    std::vector<std::vector<double>> B(N, std::vector<double>(N));
    std::vector<std::vector<double>> C(N, std::vector<double>(N, 0.0));

    // 무작위 숫자로 행렬 채우기
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 10.0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = dis(gen);
            B[i][j] = dis(gen);
        }
    }

    std::cout << N << "x" << N << " 행렬 곱셈 시작..." << std::endl;

    // ---- 시간 측정 시작 ----
    auto start = std::chrono::high_resolution_clock::now();

    //---- 핵심 알고리즘: 3중 반복문 ----
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // ---- 시간 측정 종료 ----
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    // ---- 결과 출력 ----
    std::cout << "계산 완료!" << std::endl;
    std::cout << "결과 행렬의 일부:" << std::endl;
    PrintMatrix(C); // 결과가 잘 나왔는지 일부만 확인
    std::cout << "총 실행 시간: " << diff.count() << " 초" << std::endl;

    return 0;
}