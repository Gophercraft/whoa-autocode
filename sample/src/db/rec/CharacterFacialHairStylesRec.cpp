// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/CharacterFacialHairStylesRec.hpp"
#include "util/SFile.hpp"

const char* CharacterFacialHairStylesRec::GetFilename() {
    return "DBFilesClient\\CharacterFacialHairStyles.dbc";
}

uint32_t CharacterFacialHairStylesRec::GetNumColumns() {
    return 8;
}

uint32_t CharacterFacialHairStylesRec::GetRowSize() {
    return 32;
}

bool CharacterFacialHairStylesRec::NeedIDAssigned() {
    return true;
}

int32_t CharacterFacialHairStylesRec::GetID() {
    return this->m_generatedID;
}

void CharacterFacialHairStylesRec::SetID(int32_t id) {
    this->m_generatedID = id;
}

bool CharacterFacialHairStylesRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_raceID, sizeof(this->m_raceID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_sexID, sizeof(this->m_sexID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_variationID, sizeof(this->m_variationID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_geoset[0], sizeof(m_geoset[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_geoset[1], sizeof(m_geoset[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_geoset[2], sizeof(m_geoset[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_geoset[3], sizeof(m_geoset[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_geoset[4], sizeof(m_geoset[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
