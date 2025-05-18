#ifndef INFANTRY_H
#define INFANTRY_H

#include "Unit.h"

enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

class Infantry : public Unit
{
protected:
    InfantryType infantryType;  // * Thể loại bộ binh

public:
    // * Constructor: khởi tạo với quantity, weight, pos và infantryType.
    Infantry(int quantity, int weight, Position pos, InfantryType infantryType);

    // * Override hàm getAttackScore:
    // * score = (infantryType_value * 56) + (quantity * weight)
    // * Nếu infantryType là SPECIALFORCES và weight là số chính phương thì cộng thêm 75 điểm.
    // * Sau đó, dựa trên "số cá nhân" của score (với năm 1975):
    // *   - Nếu số cá nhân > 7: tăng 20% số lượng (làm tròn lên).
    // *   - Nếu số cá nhân < 3: giảm 10% số lượng (đảm bảo quantity không nhỏ hơn 1).
    int getAttackScore() override;

    // * Override hàm str: trả về chuỗi theo định dạng
    // * "Infantry[infantryType=<infantryType>, quantity=<quantity>, weight=<weight>, pos=<pos>]"
    string str() const override;
};

#endif // INFANTRY_H