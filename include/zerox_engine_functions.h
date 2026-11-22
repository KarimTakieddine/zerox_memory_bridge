#pragma once

namespace ZeroXBridge
{
    struct Texture;

    typedef size_t (*GetFileSizeProc)(const char*);
    typedef bool (*ReadFileProc)(const char*, char*, size_t);
    typedef void (*AllocateTextureProc)(const char*, const Texture*);
    typedef void (*AllocateTextureArrayProc)(const char* const*, const Texture*, size_t);
    typedef void (*AllocateAudioProc)(const char*);
    typedef void (*PlayAudioProc)(size_t);

    struct EngineFunctions
    {
        GetFileSizeProc getFileSize                     { nullptr };
        ReadFileProc readFile                           { nullptr };
        AllocateTextureProc allocateTexture             { nullptr };
        AllocateTextureArrayProc allocateTextureArray   { nullptr };
        AllocateAudioProc allocateAudio                 { nullptr };
        PlayAudioProc playAudio                         { nullptr };
    };
}
