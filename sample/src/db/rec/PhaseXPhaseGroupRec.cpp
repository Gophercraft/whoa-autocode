// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/PhaseXPhaseGroupRec.hpp"
#include "util/SFile.hpp"

const char* PhaseXPhaseGroupRec::GetFilename() {
    return "DBFilesClient\\PhaseXPhaseGroup.dbc";
}

uint32_t PhaseXPhaseGroupRec::GetNumColumns() {
    return 3;
}

uint32_t PhaseXPhaseGroupRec::GetRowSize() {
    return 12;
}

bool PhaseXPhaseGroupRec::NeedIDAssigned() {
    return false;
}

int32_t PhaseXPhaseGroupRec::GetID() {
    return this->m_ID;
}

void PhaseXPhaseGroupRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool PhaseXPhaseGroupRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_phaseID, sizeof(this->m_phaseID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_phaseGroupID, sizeof(this->m_phaseGroupID), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
