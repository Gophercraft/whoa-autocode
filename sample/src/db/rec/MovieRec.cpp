// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/MovieRec.hpp"
#include "util/SFile.hpp"

const char* MovieRec::GetFilename() {
    return "DBFilesClient\\Movie.dbc";
}

uint32_t MovieRec::GetNumColumns() {
    return 3;
}

uint32_t MovieRec::GetRowSize() {
    return 12;
}

bool MovieRec::NeedIDAssigned() {
    return false;
}

int32_t MovieRec::GetID() {
    return this->m_ID;
}

void MovieRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool MovieRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t filenameOfs;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &filenameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_volume, sizeof(this->m_volume), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_filename = &stringBuffer[filenameOfs];
    } else {
        this->m_filename = "";
    }

    return true;
}
