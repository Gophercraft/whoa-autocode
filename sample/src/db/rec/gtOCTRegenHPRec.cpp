// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/gtOCTRegenHPRec.hpp"

const char* gtOCTRegenHPRec::GetFilename() {
    return "DBFilesClient\\gtOCTRegenHP.dbc";
}

bool gtOCTRegenHPRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_Data, sizeof(this->m_Data), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}