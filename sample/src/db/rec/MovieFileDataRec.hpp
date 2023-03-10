// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_REC_MOVIE_FILE_DATA_REC_HPP
#define DB_REC_MOVIE_FILE_DATA_REC_HPP

#include <cstdint>

class SFile;

class MovieFileDataRec {
    public:
        int32_t m_fileDataID;
        int32_t m_resolution;
        int32_t m_generatedID;

        static const char* GetFilename();
        static uint32_t GetNumColumns();
        static uint32_t GetRowSize();
        static bool NeedIDAssigned();
        int32_t GetID();
        void SetID(int32_t id);
        bool Read(SFile* f, const char* stringBuffer);
};

#endif