// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/VehicleUIIndicatorRec.hpp"

const char* VehicleUIIndicatorRec::GetFilename() {
    return "DBFilesClient\\VehicleUIIndicator.dbc";
}

bool VehicleUIIndicatorRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t BackgroundTextureOfs;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &BackgroundTextureOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_BackgroundTexture = &stringBuffer[BackgroundTextureOfs];
    } else {
        this->m_BackgroundTexture = "";
    }

    return true;
}