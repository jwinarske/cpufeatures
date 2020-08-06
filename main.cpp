#include <iostream>

#include "SkCpu.h"
#include "cpu-features.h"

void features_Mips(uint64_t features)
{
    if(features & ANDROID_CPU_MIPS_FEATURE_R6)
        std::cout << "R6" << std::endl;
    if(features & ANDROID_CPU_MIPS_FEATURE_MSA)
        std::cout << "MSA" << std::endl;
}

void features_Arm(uint64_t features)
{
    if(features & ANDROID_CPU_ARM_FEATURE_ARMv7)
        std::cout << "ARMv7" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_VFPv3)
        std::cout << "VFPv3" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_NEON)
        std::cout << "NEON" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_LDREX_STREX)
        std::cout << "LDREX_STREX" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_VFPv2)
        std::cout << "VFPv2" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_VFP_D32)
        std::cout << "VFP_D32" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_VFP_FP16)
        std::cout << "VFP_FP16" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_VFP_FMA)
        std::cout << "VFP_FMA" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_NEON_FMA)
        std::cout << "NEON_FMA" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_IDIV_ARM)
        std::cout << "IDIV_ARM" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_IDIV_THUMB2)
        std::cout << "IDIV_THUMB2" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_iWMMXt)
        std::cout << "iWMMXt" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_AES)
        std::cout << "AES" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_PMULL)
        std::cout << "PMULL" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_SHA1)
        std::cout << "SHA1" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_SHA2)
        std::cout << "SHA2" << std::endl;

    if(features & ANDROID_CPU_ARM_FEATURE_CRC32)
        std::cout << "CRC32" << std::endl;
}

void features_Aarch64(uint64_t features)
{
    if(features & ANDROID_CPU_ARM64_FEATURE_FP)
        std::cout << "FP" << std::endl;

    if(features & ANDROID_CPU_ARM64_FEATURE_ASIMD)
        std::cout << "ASIMD" << std::endl;

    if(features & ANDROID_CPU_ARM64_FEATURE_AES)
        std::cout << "AES" << std::endl;

    if(features & ANDROID_CPU_ARM64_FEATURE_PMULL)
        std::cout << "PMULL" << std::endl;

    if(features & ANDROID_CPU_ARM64_FEATURE_SHA1)
        std::cout << "SHA1" << std::endl;

    if(features & ANDROID_CPU_ARM64_FEATURE_SHA2)
        std::cout << "SHA2" << std::endl;

    if(features & ANDROID_CPU_ARM64_FEATURE_CRC32)
        std::cout << "CRC32" << std::endl;
}

void features_X86(uint64_t features)
{
    if(features & ANDROID_CPU_X86_FEATURE_SSSE3)
        std::cout << "SSSE3" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_POPCNT)
        std::cout << "POPCNT" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_MOVBE)
        std::cout << "MOVBE" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_SSE4_1)
        std::cout << "SSE4_1" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_SSE4_2)
        std::cout << "SSE4_2" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_AES_NI)
        std::cout << "AES_NI" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_AVX)
        std::cout << "AVX" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_RDRAND)
        std::cout << "RDRAND" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_AVX2)
        std::cout << "AVX2" << std::endl;

    if(features & ANDROID_CPU_X86_FEATURE_SHA_NI)
        std::cout << "SHA_NI" << std::endl;
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    AndroidCpuFamily family = android_getCpuFamily();
    uint64_t cpu_features = android_getCpuFeatures();

    switch(family)
    {
    case ANDROID_CPU_FAMILY_ARM:
        printf("CPU Family: ARM\r\n");
        features_Arm(cpu_features);
        break;
    case ANDROID_CPU_FAMILY_ARM64:
        printf("CPU Family: ARM64\r\n");
        features_Aarch64(cpu_features);
        break;
    case ANDROID_CPU_FAMILY_X86:
        printf("CPU Family: X86\r\n");
        features_X86(cpu_features);
        break;
    case ANDROID_CPU_FAMILY_X86_64:
        printf("CPU Family: X86_64\r\n");
        features_X86(cpu_features);
        break;
    case ANDROID_CPU_FAMILY_MIPS:
        printf("CPU Family: MIPS\r\n");
        features_Mips(cpu_features);
        break;
    case ANDROID_CPU_FAMILY_MIPS64:
        printf("CPU Family: MIPS64\r\n");
        features_Mips(cpu_features);
        break;
    case ANDROID_CPU_FAMILY_UNKNOWN:
    default:
        printf("CPU Family Unkown!\r\n");
        break;
    }

    int CpuCount = android_getCpuCount();
    printf("CPU Count: %d\r\n", CpuCount);

    return 0;
}
