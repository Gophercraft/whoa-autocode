// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_CHAT_CHANNELS_REC_HPP
#define DB_REC_CHAT_CHANNELS_REC_HPP

#include <cstdint>

class SFile;

class ChatChannelsRec {
    public:
        int32_t m_ID;
        int32_t m_flags;
        int32_t m_factionGroup;
        const char* m_name;
        const char* m_shortcut;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif