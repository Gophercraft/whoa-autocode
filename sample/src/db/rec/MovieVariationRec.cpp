// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/MovieVariationRec.hpp"

const char* MovieVariationRec::GetFilename() {
    return "DBFilesClient\\MovieVariation.dbc";
}

bool MovieVariationRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MovieID, sizeof(this->m_MovieID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FileDataID, sizeof(this->m_FileDataID), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}