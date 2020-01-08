// #include "../../_pch.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// using namespace std;

// ******************************
// *
// * date     : 2019/11/18
// *
// * author   : 施冠年
// * mail     : Co6901251@gmail.com
// *
// * function :
// *
// * Rsa 加解密
// *
// ******************************

// ! 文字來源 : IS_RSA
// ! http://mslab.csie.asia.edu.tw/~jackjow/courses/992_InfoSecurity/ppts/IS_RSA.pdf

// RSA 之安全性取決於質因數分解之困難度
// 要將很大的 N 因數分解成 P 跟 Q 之相乘是很困難的

// 1. 選兩個大質數 p 和 q (至少100位數), 令 N = p * q
// 2. 再計算 Ø(N) = (p - 1) * (q - 1) , 並選一個與 Ø(N) 互質數 e,
//    Ø(N) 為 Euler’s Totient 函數, 其意為與 N 互質之個數
// 3. (e,N) 即為公開金鑰, (加密法)
// 4. 選一個數 d, 滿足 (e * d) mod Ø(N) = 1, d 即為解密金鑰(亦稱私有金鑰或祕密金鑰), (解密法)

// 加密法為 C = (M ^ e) mod N ==> C = (M ^ e) mod N = 19 ^ 3 mod 33 = 28
// 解密法為 M = (C ^ d) mod N ==> M = (C ^ d) mod N = 28 ^ 7 mod 33 = 19

int main() {

    // * 輸入質數

    cout << "input (p, q) : ";
    int p, q;
    cin >> p >> q;

    // * public key

    // 若 N, N_2 為大數，可用 陣列, std::bitset, BigInt, BigInteger 解決
    int N   = p * q;             // (e, N) 公開金鑰的第二個數
    int N_2 = (p - 1) * (q - 1); // 被互質數
    int e;                       // 互質數, 與 N_2 互質

    cout << "Input e (coprime to " << N_2 << " and (1 < e <" << N_2 << ")) : ";
    cin >> e;

    // * private key

    int d = 1; // 解密金鑰
    while (((e * d) % N_2) != 1) { ++d; }

    cout << "public  key : ( e : " << e << ", N : " << N << " )" << endl;
    cout << "private key : ( d : " << d << " )" << endl;

    cout << "\nInput data ( data < " << N << " ) : ";
    int input;
    cin >> input;

    // * 加解密

    int ciphertext = input % N; // Ciphertext or Cyphertext == 密文
    for (int i = 1; i < e; ++i) { ciphertext = (ciphertext * input) % N; }
    cout << "\nCiphertext : " << ciphertext << endl;

    int plaintext = ciphertext % N; // Plaintext == 明文
    for (int i = 1; i < d; ++i) { plaintext = (plaintext * ciphertext) % N; }
    cout << "Plaintext  : " << plaintext << endl;

    system("pause");
    return 0;
}

// ! input :
// p = 3,
// q = 11,
// e = 3,
// input = 19

// ! res :
// Ciphertext : 28
// Plaintext  : 19