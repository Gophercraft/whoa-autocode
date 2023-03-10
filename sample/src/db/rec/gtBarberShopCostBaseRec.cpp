// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/gtBarberShopCostBaseRec.hpp"
#include "util/SFile.hpp"

const char* gtBarberShopCostBaseRec::GetFilename() {
    return "DBFilesClient\\gtBarberShopCostBase.dbc";
}

uint32_t gtBarberShopCostBaseRec::GetNumColumns() {
    return 1;
}

uint32_t gtBarberShopCostBaseRec::GetRowSize() {
    return 4;
}

bool gtBarberShopCostBaseRec::NeedIDAssigned() {
    return true;
}

int32_t gtBarberShopCostBaseRec::GetID() {
    return this->m_generatedID;
}

void gtBarberShopCostBaseRec::SetID(int32_t id) {
    this->m_generatedID = id;
}

bool gtBarberShopCostBaseRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_data, sizeof(this->m_data), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
