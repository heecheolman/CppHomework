#include <iostream>
#define MAX(a, b) a > b ? a : b
#define MAX_DEGREE 50

typedef struct { // 구조체 polynomial
    int degree; // 다항식의 차수를 결정
    float coef[MAX_DEGREE]; // 다항식의 각 항의 개수를 저장할 1차원 배열
} Polynomial;

// 다항식 출력함수
void printPoly(Polynomial P) {
    int degree = P.degree;
    for(int i = 0; i <= P.degree; i++) {
        printf("%3.0fx^%d", P.coef[i], degree--);
        if(i < P.degree) printf(" +");
    }
    printf("\n");
}

// 다항식의 덧셈
Polynomial addPoly(Polynomial A, Polynomial B) {
    Polynomial C;
    // 계수를 0 부터 탐색하기위한 변수 선언
    int A_index = 0, B_index = 0, C_index = 0;
    // 각 다항식의 최고차항을 저장
    int A_degree = A.degree, B_degree = B.degree;
    // 더해질 다항식의 최고차항은 두개중 최고차항
    C.degree = MAX(A.degree, B.degree);
    
    // A와 B를 모두 탐색할때까지 반복
    while(A_index <= A.degree && B_index <= B.degree) {
        // A의 차수기 B의 차수보다 클 경우
        if(A_degree > B_degree) {
            C.coef[C_index++] = A.coef[A_index++];
            A_degree--;
            // 차수가 동일할경우
        } else if(A_degree == B_degree) {
            C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
            A_degree--;
            B_degree--;
            // B의 차수가 더 클 경우
        } else {
            C.coef[C_index++] = B.coef[B_index++];
            B_degree--;
        }
    }
    return C;
}

// 다항식의 곱셈
Polynomial multiPoly(Polynomial A, Polynomial B) {
    Polynomial multi;
    int index_A = 0;
    int index_B = 0;
    int A_degree = A.degree;
    int B_degree = B.degree;
    
    // 기준이되는 A 다항식의 첫번째부터 탐색
    while(index_A <= A.degree) {
        // 곱해질 다항식에대해 임시 다항식 temp
        Polynomial temp;
        // 임시다항식의 최고차항은 두 차수의 곱셈 ( 지수법칙에의해 더해짐 )
        temp.degree = A_degree + B_degree;
        // 각 계수들을 곱해줌
        for(int i = 0; i < B.degree; i++) {
            temp.coef[i] = A.coef[index_A] * B.coef[i];
        }
        // 만들어진 temp 다항식과 결과값이 될 multi 다항식을 더해준다.
        multi = addPoly(multi, temp);
        // A의 차수를 낮추고 다음 항으로 넘어간다.
        A_degree--;
        index_A++;
    }
    // printPoly(multi);
    // 결과값이 될 multi 다항식의 최고차항을 결정해준다.
    multi.degree = A.degree + B.degree;
    return multi;
}

int main(void) {
    Polynomial a = {5, {4, 7, 1, 0, 2, 5}};
    Polynomial b = {4, {8, 3, 5, 2, 1}};
    Polynomial c;
    Polynomial d;
    c = addPoly(a, b);
    d = multiPoly(a, b);
    std::cout << "c(x) :"; printPoly(c);
    std::cout << "d(x) :"; printPoly(d);
}
