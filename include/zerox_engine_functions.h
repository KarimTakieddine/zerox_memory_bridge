#pragma once

namespace ZeroXBridge
{
    struct Texture;
    struct AudioSound;

    typedef void* EngineHandle;

    typedef size_t (*GetFileSizeProc)(const char*);
    typedef bool (*ReadFileProc)(const char*, char*, size_t);
    typedef void (*UploadTexturesProc)(EngineHandle, const char* const*, const Texture*, size_t);
    typedef void (*UploadTextureArrayProc)(EngineHandle, const char* const*, const Texture*, size_t);
    typedef void (*AllocateAudioProc)(EngineHandle, const char*, const AudioSound*);
    typedef void (*PlayAudioProc)(EngineHandle, size_t);

    struct EngineFunctions
    {
        EngineHandle handle{ nullptr };

        GetFileSizeProc getFileSize                 { nullptr };
        ReadFileProc readFile                       { nullptr };
        UploadTexturesProc uploadTextures           { nullptr };
        UploadTextureArrayProc uploadTextureArray   { nullptr };
        AllocateAudioProc allocateAudio             { nullptr };
        PlayAudioProc playAudio                     { nullptr };
    };

    inline constexpr bool isValid(const EngineFunctions* engineFunctions)
    {
        return
            engineFunctions->handle                 &&
            engineFunctions->getFileSize            &&
            engineFunctions->readFile               &&
            engineFunctions->uploadTextures         &&
            engineFunctions->uploadTextureArray     &&
            engineFunctions->allocateAudio          &&
            engineFunctions->playAudio;
    }
}
