// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/SpellVisualPrecastTransitionsRec.hpp"

const char* SpellVisualPrecastTransitionsRec::GetFilename() {
    return "DBFilesClient\\SpellVisualPrecastTransitions.dbc";
}

bool SpellVisualPrecastTransitionsRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t PrecastLoadAnimNameOfs;
    uint32_t PrecastHoldAnimNameOfs;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &PrecastLoadAnimNameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &PrecastHoldAnimNameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_PrecastLoadAnimName = &stringBuffer[PrecastLoadAnimNameOfs];
        this->m_PrecastHoldAnimName = &stringBuffer[PrecastHoldAnimNameOfs];
    } else {
        this->m_PrecastLoadAnimName = "";
        this->m_PrecastHoldAnimName = "";
    }

    return true;
}