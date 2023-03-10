// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/SpellItemEnchantmentConditionRec.hpp"
#include "util/SFile.hpp"

const char* SpellItemEnchantmentConditionRec::GetFilename() {
    return "DBFilesClient\\SpellItemEnchantmentCondition.dbc";
}

uint32_t SpellItemEnchantmentConditionRec::GetNumColumns() {
    return 31;
}

uint32_t SpellItemEnchantmentConditionRec::GetRowSize() {
    return 64;
}

bool SpellItemEnchantmentConditionRec::NeedIDAssigned() {
    return false;
}

int32_t SpellItemEnchantmentConditionRec::GetID() {
    return this->m_ID;
}

void SpellItemEnchantmentConditionRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool SpellItemEnchantmentConditionRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperandType[0], sizeof(m_ltOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperandType[1], sizeof(m_ltOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperandType[2], sizeof(m_ltOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperandType[3], sizeof(m_ltOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperandType[4], sizeof(m_ltOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperand[0], sizeof(m_ltOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperand[1], sizeof(m_ltOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperand[2], sizeof(m_ltOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperand[3], sizeof(m_ltOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ltOperand[4], sizeof(m_ltOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_operator[0], sizeof(m_operator[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_operator[1], sizeof(m_operator[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_operator[2], sizeof(m_operator[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_operator[3], sizeof(m_operator[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_operator[4], sizeof(m_operator[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperandType[0], sizeof(m_rtOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperandType[1], sizeof(m_rtOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperandType[2], sizeof(m_rtOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperandType[3], sizeof(m_rtOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperandType[4], sizeof(m_rtOperandType[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperand[0], sizeof(m_rtOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperand[1], sizeof(m_rtOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperand[2], sizeof(m_rtOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperand[3], sizeof(m_rtOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rtOperand[4], sizeof(m_rtOperand[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_logic[0], sizeof(m_logic[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_logic[1], sizeof(m_logic[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_logic[2], sizeof(m_logic[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_logic[3], sizeof(m_logic[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_logic[4], sizeof(m_logic[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
