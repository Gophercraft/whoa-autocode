// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/UnitBloodRec.hpp"
#include "util/SFile.hpp"

const char* UnitBloodRec::GetFilename() {
    return "DBFilesClient\\UnitBlood.dbc";
}

uint32_t UnitBloodRec::GetNumColumns() {
    return 10;
}

uint32_t UnitBloodRec::GetRowSize() {
    return 40;
}

bool UnitBloodRec::NeedIDAssigned() {
    return false;
}

int32_t UnitBloodRec::GetID() {
    return this->m_ID;
}

void UnitBloodRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool UnitBloodRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t groundBloodOfs[5];

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_combatBloodSpurtFront[0], sizeof(m_combatBloodSpurtFront[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_combatBloodSpurtFront[1], sizeof(m_combatBloodSpurtFront[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_combatBloodSpurtBack[0], sizeof(m_combatBloodSpurtBack[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_combatBloodSpurtBack[1], sizeof(m_combatBloodSpurtBack[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &groundBloodOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &groundBloodOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &groundBloodOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &groundBloodOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &groundBloodOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_groundBlood[0] = &stringBuffer[groundBloodOfs[0]];
        this->m_groundBlood[1] = &stringBuffer[groundBloodOfs[1]];
        this->m_groundBlood[2] = &stringBuffer[groundBloodOfs[2]];
        this->m_groundBlood[3] = &stringBuffer[groundBloodOfs[3]];
        this->m_groundBlood[4] = &stringBuffer[groundBloodOfs[4]];
    } else {
        this->m_groundBlood[0] = "";
        this->m_groundBlood[1] = "";
        this->m_groundBlood[2] = "";
        this->m_groundBlood[3] = "";
        this->m_groundBlood[4] = "";
    }

    return true;
}
