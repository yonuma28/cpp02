/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:43:58 by yonuma            #+#    #+#             */
/*   Updated: 2025/12/27 18:08:18 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main( void ) {
    // 1. 基本テスト (PDFのサンプル)
    {
        std::cout << "--- 1. Basic Tests (PDF) ---" << std::endl;
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }

    // 2. 算術演算テスト
    {
        std::cout << "\n--- 2. Arithmetic Tests ---" << std::endl;
        Fixed const a(21.5f);
        Fixed const b(2);
        
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "a + b = " << (a + b) << std::endl;
        std::cout << "a - b = " << (a - b) << std::endl;
        std::cout << "a * b = " << (a * b) << std::endl;
        std::cout << "a / b = " << (a / b) << std::endl;
        // 注意: 0除算はクラッシュしても良いとされています [cite: 299]
    }

    // 3. 比較演算テスト
    {
        std::cout << "\n--- 3. Comparison Tests ---" << std::endl;
        Fixed const a(10);
        Fixed const b(10.01f);
        Fixed const c(10);

        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
        std::cout << "a < b  : " << (a < b) << " (Expected: 1)" << std::endl;
        std::cout << "a > b  : " << (a > b) << " (Expected: 0)" << std::endl;
        std::cout << "a <= c : " << (a <= c) << " (Expected: 1)" << std::endl;
        std::cout << "a >= c : " << (a >= c) << " (Expected: 1)" << std::endl;
        std::cout << "a == c : " << (a == c) << " (Expected: 1)" << std::endl;
        std::cout << "a != b : " << (a != b) << " (Expected: 1)" << std::endl;
    }

    // 4. インクリメント・デクリメントテスト (前置・後置)
    {
        std::cout << "\n--- 4. Increment/Decrement Tests ---" << std::endl;
        Fixed a(0);
        
        std::cout << "Initial a: " << a << std::endl;
        std::cout << "++a      : " << ++a << std::endl;
        std::cout << "--a      : " << --a << std::endl;
        std::cout << "a++      : " << a++ << std::endl;
        std::cout << "After a++: " << a << std::endl;
        std::cout << "a--      : " << a-- << std::endl;
        std::cout << "After a--: " << a << std::endl;
        
        // 最小単位 epsilon の確認
        Fixed b(1);
        std::cout << "1 + epsilon: " << ++b << " (Should be 1 + 1/256)" << std::endl;
    }

    // 5. Min/Max テスト (const参照と非const参照の区別)
    {
        std::cout << "\n--- 5. Min/Max Tests ---" << std::endl;
        Fixed a(10);
        Fixed b(20);
        Fixed const c(30);
        Fixed const d(40);

        std::cout << "min(a, b)      : " << Fixed::min(a, b) << std::endl;
        std::cout << "max(c, d)      : " << Fixed::max(c, d) << " (const version)" << std::endl;
        
        // 非const版が正しく参照を返しているかの確認
        Fixed::max(a, b) = Fixed(100);
        std::cout << "Modified b via max(a, b): " << b << " (Expected: 100)" << std::endl;
    }

    return 0;
}
