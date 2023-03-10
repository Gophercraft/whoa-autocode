// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_QUEST_SORT_REC_HPP
#define DB_REC_QUEST_SORT_REC_HPP

#include <cstdint>

class SFile;

class QuestSortRec {
    public:
        int32_t m_ID;
        const char* m_sortName;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif