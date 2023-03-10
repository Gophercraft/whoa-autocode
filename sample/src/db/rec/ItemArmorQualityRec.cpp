// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/ItemArmorQualityRec.hpp"
#include "util/SFile.hpp"

const char* ItemArmorQualityRec::GetFilename() {
    return "DBFilesClient\\ItemArmorQuality.dbc";
}

uint32_t ItemArmorQualityRec::GetNumColumns() {
    return 9;
}

uint32_t ItemArmorQualityRec::GetRowSize() {
    return 36;
}

bool ItemArmorQualityRec::NeedIDAssigned() {
    return false;
}

int32_t ItemArmorQualityRec::GetID() {
    return this->m_ID;
}

void ItemArmorQualityRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool ItemArmorQualityRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_qualitymod[0], sizeof(m_qualitymod[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_qualitymod[1], sizeof(m_qualitymod[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_qualitymod[2], sizeof(m_qualitymod[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_qualitymod[3], sizeof(m_qualitymod[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_qualitymod[4], sizeof(m_qualitymod[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_qualitymod[5], sizeof(m_qualitymod[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_qualitymod[6], sizeof(m_qualitymod[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_itemLevel, sizeof(this->m_itemLevel), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
