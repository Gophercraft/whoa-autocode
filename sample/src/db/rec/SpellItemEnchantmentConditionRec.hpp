// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_SPELL_ITEM_ENCHANTMENT_CONDITION_REC_HPP
#define DB_REC_SPELL_ITEM_ENCHANTMENT_CONDITION_REC_HPP

#include <cstdint>

class SFile;

class SpellItemEnchantmentConditionRec {
    public:
        int32_t m_ID;
        int8_t m_ltOperandType[5];
        int32_t m_ltOperand[5];
        int8_t m_operator[5];
        int8_t m_rtOperandType[5];
        int32_t m_rtOperand[5];
        int8_t m_logic[5];

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif