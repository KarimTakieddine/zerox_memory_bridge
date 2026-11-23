#pragma once

namespace ZeroXBridge
{
    struct Texture;
    struct AudioSound;

    typedef void* EngineHandle;

    typedef size_t (*GetFileSizeProc)(const char*);
    typedef bool (*ReadFileProc)(const char*, char*, size_t);
    typedef void (*AllocateTexturesProc)(EngineHandle, const char* const*, const Texture*, size_t);
    typedef void (*AllocateTextureArrayProc)(EngineHandle, const char* const*, const Texture*, size_t);
    typedef void (*AllocateAudioProc)(EngineHandle, const char*, const AudioSound*);
    typedef void (*PlayAudioProc)(EngineHandle, size_t);

    struct EngineFunctions
    {
        EngineHandle handle{ nullptr };

        GetFileSizeProc getFileSize                     { nullptr };
        ReadFileProc readFile                           { nullptr };
        AllocateTexturesProc allocateTextures           { nullptr };
        AllocateTextureArrayProc allocateTextureArray   { nullptr };
        AllocateAudioProc allocateAudio                 { nullptr };
        PlayAudioProc playAudio                         { nullptr };
    };

    inline constexpr bool isValid(const EngineFunctions* engineFunctions)
    {
        return
            engineFunctions->handle                 &&
            engineFunctions->getFileSize            &&
            engineFunctions->readFile               &&
            engineFunctions->allocateTextures       &&
            engineFunctions->allocateTextureArray   &&
            engineFunctions->allocateAudio          &&
            engineFunctions->playAudio;
    }
}
