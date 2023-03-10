// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/Achievement_CriteriaRec.hpp"
#include "util/SFile.hpp"

const char* Achievement_CriteriaRec::GetFilename() {
    return "DBFilesClient\\Achievement_Criteria.dbc";
}

uint32_t Achievement_CriteriaRec::GetNumColumns() {
    return 31;
}

uint32_t Achievement_CriteriaRec::GetRowSize() {
    return 124;
}

bool Achievement_CriteriaRec::NeedIDAssigned() {
    return false;
}

int32_t Achievement_CriteriaRec::GetID() {
    return this->m_ID;
}

void Achievement_CriteriaRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool Achievement_CriteriaRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t descriptionOfs[16];
    uint32_t descriptionMask;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_achievementID, sizeof(this->m_achievementID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_type, sizeof(this->m_type), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_assetID, sizeof(this->m_assetID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_quantity, sizeof(this->m_quantity), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_startEvent, sizeof(this->m_startEvent), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_startAsset, sizeof(this->m_startAsset), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_failEvent, sizeof(this->m_failEvent), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_failAsset, sizeof(this->m_failAsset), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &descriptionMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_flags, sizeof(this->m_flags), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_timerStartEvent, sizeof(this->m_timerStartEvent), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_timerAssetID, sizeof(this->m_timerAssetID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_timerTime, sizeof(this->m_timerTime), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_uiOrder, sizeof(this->m_uiOrder), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_description = &stringBuffer[descriptionOfs[CURRENT_LANGUAGE]];
    } else {
        this->m_description = "";
    }

    return true;
}
