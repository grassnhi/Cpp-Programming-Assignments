#ifndef _H_TERRAIN_ELEMENT_H_
#define _H_TERRAIN_ELEMENT_H_

class Army; // Forward declaration

#include "Army.h"

//-----------------------------------------------------
// CLASS TerrainElement và các lớp dẫn xuất
//-----------------------------------------------------
class TerrainElement {
protected:
    Position pos; // Vị trí của yếu tố địa hình
    // Phương thức tính khoảng cách giữa hai vị trí
    double calculateDistance(const Position& pos1, const Position& pos2) {
        int rowDiff = pos1.getRow() - pos2.getRow();
        int colDiff = pos1.getCol() - pos2.getCol();
        return (sqrt(double(rowDiff * rowDiff + colDiff * colDiff)));
    }
    int safeCeil(double value) {
        double diff = abs(value - round(value));
        return (diff < 1e-9) ? round(value) : ceil(value);
    }
public:
    TerrainElement(Position);
    virtual ~TerrainElement();
    // Phương thức thuần ảo: áp dụng hiệu ứng của yếu tố địa hình lên các quân đội.
    // (Chú ý: dùng tham số kiểu Army** theo đề bài.)
    virtual void getEffect(Army *army) = 0;
};

class Road : public TerrainElement {
public:
    Road(Position pos) : TerrainElement(pos) {}
    // Đường mòn không có hiệu ứng
    void getEffect(Army *army);
};

class Mountain : public TerrainElement {
public:
    Mountain(Position pos) : TerrainElement(pos) {}
    // Rừng núi: hiệu ứng áp dụng (stub) – áp dụng tác động đối với cả các đơn vị bộ binh và phương tiện
    void getEffect(Army *army);
};

class River : public TerrainElement {
public:
    River(Position pos) : TerrainElement(pos) {}
    // Sông: hiệu ứng giảm EXP 10% cho lực lượng bộ binh nếu nằm trong bán kính 2 đơn vị (stub)
    void getEffect(Army *army);
};

class Urban : public TerrainElement {
public:
    Urban(Position pos) : TerrainElement(pos) {}
    // Khu dân cư: hiệu ứng (stub) – áp dụng theo mô tả đề bài
    void getEffect(Army *army);
};

class Fortification : public TerrainElement {
public:
    Fortification(Position pos) : TerrainElement(pos) {}
    // Chiến hào: hiệu ứng (stub) – áp dụng theo mô tả đề bài
    void getEffect(Army *army);
};

class SpecialZone : public TerrainElement {
public:
    SpecialZone(Position pos) : TerrainElement(pos) {}
    // Khu vực phi quân sự: hiệu ứng (stub) – đặt attackScore của các đơn vị xung quanh về 0
    void getEffect(Army *army);
};

#endif