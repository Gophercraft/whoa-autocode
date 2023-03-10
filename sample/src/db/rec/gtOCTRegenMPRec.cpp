// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/gtOCTRegenMPRec.hpp"
#include "util/SFile.hpp"

const char* gtOCTRegenMPRec::GetFilename() {
    return "DBFilesClient\\gtOCTRegenMP.dbc";
}

uint32_t gtOCTRegenMPRec::GetNumColumns() {
    return 1;
}

uint32_t gtOCTRegenMPRec::GetRowSize() {
    return 4;
}

bool gtOCTRegenMPRec::NeedIDAssigned() {
    return true;
}

int32_t gtOCTRegenMPRec::GetID() {
    return this->m_generatedID;
}

void gtOCTRegenMPRec::SetID(int32_t id) {
    this->m_generatedID = id;
}

bool gtOCTRegenMPRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_data, sizeof(this->m_data), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
