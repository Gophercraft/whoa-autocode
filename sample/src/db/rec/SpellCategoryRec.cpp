// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/SpellCategoryRec.hpp"

const char* SpellCategoryRec::GetFilename() {
    return "DBFilesClient\\SpellCategory.dbc";
}

bool SpellCategoryRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Flags, sizeof(this->m_Flags), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}