/**
 * amb/Font.cpp
 */

#include <amb/Font.h>

namespace amb {

// const Font Font::s_luxirb(FontNames::luxirb);
// const Font Font::s_luxirbi(FontNames::luxirbi);

const Font Font::defaults[] = {
    Font(FontNames::Cantarell_Bold),  // 0
                                      // Font(FontNames::Cantarell_Regular),
                                      // Font(FontNames::Carlito_BoldItalic),
                                      // Font(FontNames::Carlito_Bold),
                                      // Font(FontNames::Carlito_Italic),
    // Font(FontNames::Carlito_Regular) //, // 5
    // Font(FontNames::DejaVuSans_BoldOblique),
    // Font(FontNames::DejaVuSans_Bold),
    // Font(FontNames::DejaVuSansCondensed_BoldOblique),
    // Font(FontNames::DejaVuSansCondensed_Bold),
    // Font(FontNames::DejaVuSansCondensed_Oblique), // 10
    // Font(FontNames::DejaVuSansCondensed),
    // Font(FontNames::DejaVuSans_ExtraLight),
    // Font(FontNames::DejaVuSansMono_BoldOblique),
    // Font(FontNames::DejaVuSans_Bold),
    // Font(FontNames::DejaVuSansCondensed_BoldOblique), // 15
    // Font(FontNames::DejaVuSansCondensed_Bold),
    // Font(FontNames::DejaVuSansCondensed_Oblique),
    // Font(FontNames::DejaVuSansCondensed),
    // Font(FontNames::DejaVuSans_ExtraLight),
    // Font(FontNames::DejaVuSansMono_BoldOblique), // 20
    // Font(FontNames::DejaVuSansMono_Bold),
    // Font(FontNames::DejaVuSansMono_Oblique),
    // Font(FontNames::DejaVuSansMono),
    // Font(FontNames::DejaVuSans_Oblique),
    // Font(FontNames::DejaVuSans),        // 25
    // Font(FontNames::DejaVuSerif_BoldItalic),
    // Font(FontNames::DejaVuSerif_Bold),
    // Font(FontNames::DejaVuSerifCondensed_BoldItalic),
    // Font(FontNames::DejaVuSerifCondensed_Bold),
    // Font(FontNames::DejaVuSerifCondensed_Italic), // 30
    // Font(FontNames::DejaVuSerifCondensed),
    // Font(FontNames::DejaVuSerif_Italic),
    // Font(FontNames::DejaVuSerif),
    // Font(FontNames::DroidKufi_Bold),
    // Font(FontNames::DroidKufi_Regular),      // 35
    // Font(FontNames::DroidNaskh_Bold),
    // Font(FontNames::DroidNaskh_Regular_SystemUI),
    // Font(FontNames::DroidNaskh_Regular),
    // Font(FontNames::DroidSansArmenian),
    // Font(FontNames::DroidSans_Bold),            // 40
    // Font(FontNames::DroidSansDevanagari_Regular),
    // Font(FontNames::DroidSansEthiopic_Bold),
    // Font(FontNames::DroidSansEthiopic_Regular),
    // Font(FontNames::DroidSansFallbackFull),
    // Font(FontNames::DroidSansGeorgian),   // 45
    // Font(FontNames::DroidSansHebrew_Bold),
    // Font(FontNames::DroidSansHebrew_Regular),
    // Font(FontNames::DroidSansJapanese),
    // Font(FontNames::DroidSansMono),
    // Font(FontNames::DroidSansTamil_Bold), // 50
    // Font(FontNames::DroidSansTamil_Regular),
    // Font(FontNames::DroidSansThai),
    // Font(FontNames::DroidSans),
    // Font(FontNames::DroidSerif_BoldItalic),
    // Font(FontNames::DroidSerif_Bold), // 55
    // Font(FontNames::DroidSerif_Italic),
    // Font(FontNames::DroidSerif_Regular),
    // Font(FontNames::FreeMonoBoldOblique),
    // Font(FontNames::FreeMonoBold),
    // Font(FontNames::FreeMonoOblique), // 60
    // Font(FontNames::FreeMono),
    // Font(FontNames::FreeSansBoldOblique),
    // Font(FontNames::FreeSansBold),
    // Font(FontNames::FreeSansOblique),
    // Font(FontNames::FreeSans),      // 65
    // Font(FontNames::FreeSerifBoldItalic),
    // Font(FontNames::FreeSerifBold),
    // Font(FontNames::FreeSerifItalic),
    // Font(FontNames::FreeSerif),
    // Font(FontNames::GohaTibebZemen), // 70
    // Font(FontNames::LiberationMono_BoldItalic),
    // Font(FontNames::LiberationMono_Bold),
    // Font(FontNames::LiberationMono_Italic),
    // Font(FontNames::LiberationMono_Regular),
    // Font(FontNames::LiberationSans_BoldItalic), // 75
    // Font(FontNames::LiberationSans_Bold),
    // Font(FontNames::LiberationSans_Italic),
    // Font(FontNames::LiberationSansNarrow_BoldItalic),
    // Font(FontNames::LiberationSansNarrow_Bold),
    // Font(FontNames::LiberationSansNarrow_Italic), // 80
    // Font(FontNames::LiberationSansNarrow_Regular),
    // Font(FontNames::LiberationSans_Regular),
    // Font(FontNames::LiberationSerif_BoldItalic),
    // Font(FontNames::LiberationSerif_Bold),
    // Font(FontNames::LiberationSerif_Italic), // 85
    // Font(FontNames::LiberationSerif_Regular),
    // Font(FontNames::luximbi),
    // Font(FontNames::luximb),
    // Font(FontNames::luximri),
    // Font(FontNames::luximr), // 90
    // Font(FontNames::luxirbi),
    // Font(FontNames::luxirb),
    // Font(FontNames::luxirri),
    // Font(FontNames::luxirr),
    // Font(FontNames::luxisbi), // 95
    // Font(FontNames::luxisb),
    // Font(FontNames::luxisri),
    // Font(FontNames::luxisr),
    // Font(FontNames::OpenSans_BoldItalic),
    // Font(FontNames::OpenSans_Bold),   // 100
    // Font(FontNames::OpenSans_CondBold),
    // Font(FontNames::OpenSans_CondLightItalic),
    // Font(FontNames::OpenSans_CondLight),
    // Font(FontNames::OpenSans_ExtraBoldItalic),
    // Font(FontNames::OpenSans_ExtraBold),  // 105
    // Font(FontNames::OpenSans_Italic),
    // Font(FontNames::OpenSans_LightItalic),
    // Font(FontNames::OpenSans_Light),
    // Font(FontNames::OpenSans_Regular),
    // Font(FontNames::OpenSans_SemiboldItalic), // 110
    // Font(FontNames::OpenSans_Semibold),
    // Font(FontNames::SyrCOMAdiabene),
    // Font(FontNames::SyrCOMAntioch),
    // Font(FontNames::SyrCOMBatnanBold),
    // Font(FontNames::SyrCOMBatnan), // 115
    // Font(FontNames::SyrCOMCtesiphon),
    // Font(FontNames::SyrCOMEdessa),
    // Font(FontNames::SyrCOMJerusalemBold),
    // Font(FontNames::SyrCOMJerusalemItalic),
    // Font(FontNames::SyrCOMJerusalem),    // 120
    // Font(FontNames::SyrCOMJerusalemOutline),
    // Font(FontNames::SyrCOMKharput),
    // Font(FontNames::SyrCOMMalankara),
    // Font(FontNames::SyrCOMMardinBold),
    // Font(FontNames::SyrCOMMardin),   // 125
    // Font(FontNames::SyrCOMMidyat),
    // Font(FontNames::SyrCOMNisibin),
    // Font(FontNames::SyrCOMNisibinOutline),
    // Font(FontNames::SyrCOMQenNeshrin),
    // Font(FontNames::SyrCOMTalada),  // 130
    // Font(FontNames::SyrCOMTurAbdin),
    // Font(FontNames::SyrCOMUrhoyBold),
    // Font(FontNames::SyrCOMUrhoy), // 133
    // Font(FontNames::yudit)
};

Font::Font(const std::string& fontFile) : sf::Font() { loadFromFile(fontFile); }

}  // End namespace amb
