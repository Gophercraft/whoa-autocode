// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/SpellInterruptsRec.hpp"

const char* SpellInterruptsRec::GetFilename() {
    return "DBFilesClient\\SpellInterrupts.dbc";
}

bool SpellInterruptsRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_AuraInterruptFlags[0], sizeof(m_AuraInterruptFlags[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_AuraInterruptFlags[1], sizeof(m_AuraInterruptFlags[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ChannelInterruptFlags[0], sizeof(m_ChannelInterruptFlags[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ChannelInterruptFlags[1], sizeof(m_ChannelInterruptFlags[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_InterruptFlags, sizeof(this->m_InterruptFlags), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}