#include "gtest/gtest.h"

#include <iostream>
#include <string>

#include <iota/iota.h>
#include <iota/internal.h>

TEST(SignTest, Digests) {
  auto expectedTrytes = "P9ZFUIEJXGKJHZBNDQHYGJCACVNZHP9FBADFDCIVPQHTOWMKJJPUVX"
                        "ESGKTDVLRONDAXFEBYECRRESHTCBXZDRHM9EFGWGQVSS9KDHEBDXMF"
                        "YTQHCANZZZYEVWHTWGTNSNAKCTJWPQQDLXUCQJAYRWSTAUZFSHFXC"
                        "Q";
  auto seed = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
              "AAAAAAAAAAAAAAAAA";
  auto computed = iota_generateKey(seed, 0, 2);
  auto digests = iota_digests(computed);

  EXPECT_EQ(expectedTrytes, std::string(digests));

  free((void*) computed);
  free((void*) digests);
}

TEST(SignTest, Sign) {
  std::string seed =
      "WQNZOHUT99PWKEBFSKQSYNC9XHT9GEBMOSJAQDQAXPEZPJNDIUB9TSNWVMHKWICW9WVZXSMD"
      "FGISOD9FZ";
  std::string bundleHash =
      "DEXRPLKGBROUQMKCLMRPG9HFKCACDZ9AB9HOJQWERTYWERJNOYLW9PKLOGDUPC9DLGSU"
      "H9UHSKJOASJRU";
  std::string csign0 =
      "QQ9VLGQTJICJH9UZNSBXRSKBWVXCTRNGLJPEYFSZBISDCGBHGAV9TEHIMJS9LMQN"
      "HFNWVAXALKGESPWZMUMZPQCKCUFSEJZVHWZHZOEZBPTERXPHUQLQLZMENKOKAWMJ"
      "9LCFSIBSBEYCJQVQQMTMRJMDEKRXLCIRZFWQBRJYLPSK9XLWFYFTU9FBJATWPQRJ"
      "BHWYJRUEXSXMBJLVWNYRTZJTHLEKDTWCGJ9OXDEZNWTKLTXXTKVFXDMRJUDAMDAC"
      "RHJKZIJFJBZRVDLSTIMOWPTLLIVHCFUBMSQIPVPCSQAPZGHHNNQLWEHDTIQZQTAX"
      "JMTTROYOTIZSZKKQFXBHXFKSNAGZWHWEGXCKHSJQGBJGC9IKUSSJEAOHTPGPMIYP"
      "EXJXJKRLX9IOCUDKK9ONEUONYVGHRHXSAUZJXGVQNWSDZIYXXZMMJKRTOXSWJHBI"
      "MXPEMJTKIBSQKPICTKAQLJVOLZSGNVVBIOFJJKKJ9UBYKJWCBRPQLGBNEKEFRYCH"
      "B9PORAKEKTJZYZBFGZLONUJCPNINGUTYWTMDKTEPDASCHNVHXTUIOZ9PDALXKQYL"
      "ILMUJEJWTYYAGEQXNNPLOMFGHSTFCNRMDFUSQREHFASDXZZOYNWNVKCRFZIDF9X9"
      "YKME9O9NJH9LFVNNSOXHSQOMBULFHBBPSGRCCGKWENQOZHRSIIHKKXAQTFISNVGI"
      "VMBDKSJYDW9VTZBAVYWWJAIYSCHGBIXKMKHBRTHWQMIWQVPWFUJQVUDZRDX9MMCX"
      "OQTQZGKECGIHATHUC9TDGKUKOYXEEBGTQYEO9KADOSMYWGQARTIUG9IUHQEBWSFH"
      "WDZCRCH9WDRJEUSQDBBGGKTOYBKYZX9LUKUGBVTEPXDOVVNSKPUWNARSILQNOQKA"
      "TCUHMRVMKVHF9B9TEJDOMBDXLNKDJI9IIYRXNOQPBOVOEEGQFSZJJOFPNFVXOYZN"
      "LSOOA9FWDFJKDOQUHWHBNDWQZZVRBZJSLDVBRCGFCWXNUFTMLCHNXODSQMUIBPN9"
      "NMAXZXKUYYRUEDSLW9UEQYGSEBEOHGI9W9WAUFDEQCXVYOTBAAHFXHRGJBWGFZKI"
      "UMSWEXAD9EDALOOYQZIXKUOWJDHBHSEUDPJJRXANPPHUZWJM9KDVGJUAQHFJTWNF"
      "SULGSWMGMAOCAHTIYYJONOLKGNKRXWWZYWKITSFPQJNHQWAIJULYWPXQENPZTWZI"
      "SXJBWYLENOINLFBRWWGWSWJONHIA99VGCSAT9XNMZUCSVEJMZJASUSXVUWFSVFXU"
      "IFWGIFKLEFLANHTITFCOPXRXTDXRDHLWP9RJHVQJMLPBFVHTIOQMSZECNPITTBTP"
      "LUHDQQZP9BWTWIZSOTMTZQWHCETRTKQPOHPJMJMLSBWC9ZRQAZDLAPJHAXRQZ9RU"
      "HHBPASWVUHBYX9FH9PLEHQEKCOMIHUNDVKOPKXEFM9CNP9LOLMBVHMMWNDCKHSYZ"
      "EXOJAQOHMRXEGWMWFW9YVOZ9YDPHWVTKWFYUECSROYJENFPSIKHBJRSNWO9KQUEN"
      "GPVULVYAQFAIYFSNIYR9LLRMYNCNQQAOPFNMWFSWSPMWNNIRNVKDZWRLGMPCBOVI"
      "MMXEZUFYPFPIGWTGOLDAEBZQADSOGVDZXHEWZGHNAAHMFPSOZD9SEPNCW9GTN9WL"
      "FDDCKMMXPXAEUUJPJFKKWMGUKVMYBH9AIEFAIIDJOAWRDKECA99XOYRSFZQKTVRJ"
      "MTUAQJZUTKGXROESUYYSHTLRIZRPSNDFEEZWXCQONZYCD9TOHCBP9ISXQ9YSRZJ9"
      "99Z9TETYOINSDGRBQSDTVFABHQNLTWGFYLHBHPVKLIBUMLVSURAOS9QHXDTIPKOJ"
      "DLYOKRCEKCBMKVYIAKVA9WTGDWHIRUAWOVRKOSYTNIZAZNTJRFJDMNLGHTDKPKZD"
      "LBPQXRIRIVREMOBCPHMBBAUKNXHU9XIZNG9GD9LDIBBFPSI9PJNRCHXHNWAZXIAC"
      "E9LUBNUWOK9LGJ9MKZQRI9CBCJUNALQKKVGGSPRJFAGCXNFO99YMLMKI9NVUZCZ9"
      "BCUEBSGMAVNKGWYWWQPZISMKAROXLQWEHOJIJOIIYRUDBNHRD9DEDQWQONAXKKSY"
      "MYCFTITZFKIXKZCGAVAFQIYEMESOIMWUUDSXJRR9RVWTAAHCOA9SCQBF9LAGPPYD"
      "XPEBKLHZ9KH";
  std::string csign1 = "NQCCBPFGGLFQR9OCCCVZBXTDQXFPQN9IKEMOZMIVUTVMSYMDWPGZNJHH9JLP"
                "QTBI9LG9NJRUVUIQQLOHNEKMHCXPAICLEBEQTTQ9ELXKYXLRPDNEPURKPWVV"
                "QKBPTQLOOKCQOPOERDFRULBZQZDZMWKMQGEMKBLWIZPCXK9F9RMFMFHRFEDF"
                "CQXLC9OUHYVAQNGRFCFBQSZWQAJVZEIGQKHUMKIGUIHHEKKBQCGZGKZZNPVD"
                "VSENPGDQQJKSOBHZTMDBSUKHUVMJWODYAYGZZGZKBKJZOXDRINRAGKHHXFPS"
                "RPXUQAGBQVGVVHEXEL9UHVDELXBFBAJQZZNOVEDTP9XSRPYIWKUVSGWI9TRD"
                "ZEEVSRFTYLBNPYCIOFKIMO9WN9VPZQDMFBRVWGEIETPVIQBECGTRIIBUEXQC"
                "W9XSBEUTTY9TOHSNVYTVIXYDDPSLSWRFQZYGNCMFYZWSHNLPZSQKJQXGQSLR"
                "OFVIBRKMDXBDPIEFXQSYNCFNYWFZUVSGEEEGQNME9IPQKUMQCOKTXZHXHEBV"
                "WQEFORYKRRZDRQTONMYONUOITKEZIDJJKWLQKXNJAK9ZPVIYROIHNVE9SIRI"
                "FBWVFTUBIGDZC9DKOIM9LKFPKULKNXRB9IGJ9EPLEHIONH99QORUNHNDZDJR"
                "DRLQPF9DMEFMHUOCAXJVOAHQPXL9TYTMSOYULAOZG9KICMCXYRLXLHAL9XHM"
                "DEMXUNNST9FWHAZDLEHWTPZRKZ9VPWGZJKMLO9OQXKFVCOBXNHPSXXNUFSUF"
                "ZBZCREYXSJCGGGMNBGPQIZXCMWEVIIWBPLLWACY9YHWGBJBGSPAVPQFJYTKV"
                "IFBIGUDUMVRZBZXNC99RQAERIAMB99DYNJRDMCX9AJPLIWNNJFFYQBTZCILV"
                "BPUN9KQCA9CQI9JVTULVNE9D99ET9TNUCRNWLOMZ9OP9ZHXNNDFXYRYFHFMJ"
                "JQHKRAJSLBDLGZWDR9VKTXWBUKUEUWCLJBSTULNQEEFZTSGDNDXFQHQTGZTV"
                "JWTXMGP9SEOAILBQBZGNZFTLDFDDPPYJNKGMYQQFACIW9XDTDHCEQGTZVVCX"
                "APCYIFPLLQTDBQXZFYSJDNZGBXRLOJCMAHGZDLTECSLUZDZLGWN9UZPUJMUZ"
                "CNGDBUPWLAWLNEJHDXRZ9IQKYCJJALWYXANSAUTLHT9CMXZDRZ99XNWDOQMO"
                "UMLMAINJDOJWMUDPOARMSUSRXKYR9CCRIMCVA9XUMWPLQTGEJOIKWHKIMPAV"
                "KOMQDVPXA9PIZFZ9LTEWKVGWDIABHRORKRRESIWBHPZYIHDGCXSXEKZRWSSM"
                "XJOXPHWIF9PJA9WJG9EZISSLGRLZFCZZEZADKVAPSWRKUK9ETWFCWDYKKPIT"
                "KIGINQXPNIYN9OUBLGJGTZCCNURCOXWDAHBPXZHSREMNEXQS9HLULAHYURRX"
                "SFXCZXKGNJRSYHO9O9FILRTIEQJOBYVGEWIWVOSHRLWBVNNXAAPSOVFKZLYW"
                "KQQGPOYOZV9QNYULGLXQMTZDRSHUPSKKTHVTEEBPCDHPIELVXMKWXESICBNX"
                "ESDNOOLTTDDRZECGXDCDA9HUWHVGHO9L9GKSTFKXASLXZXBYJIMUMBFXGEMF"
                "TPGFCGQNICCSMCWLTEBEIYWMWXOUAHWAGLINDEGGHAKWZ9OGGHOIRC9UYRIW"
                "9TAPKEANNSVZELHDUTC9BFUDNXSFUNZWYOZMEVFRTROERURUZEIDBLNETCWS"
                "CALTEVPXRUJPVBBAXZ9RCPDTLHEJTJOIYDXK9NNIIUTZBLFSYKYUOZCNHFCH"
                "PNFCFTYXND9YW9FNQPU9IIWFFBECJAZPKMMCIYGXYQVHXXVWEBIQ9WPLPDQC"
                "9BAYNQ9QAKIWSIAPMDEANCPDA9XMLRAKVJDMRNGKGLXYDWPVBTA9EKFLTHYH"
                "SS9ZGYXH9FSGJFHAZ9VZCVEFHLPDKOOFCOVOVQHGSINH9FTRCMUZPVSAVZQB"
                "NOBUDZYO9NABYNLAHVUITA9EVOSBRWAQKLQSZYEYUAYOOQVWDM9QYJHXVDZH"
                "WRNPQGPERE9GRSNRGFZEUAAKPLFJYHYEHXSMTOVFSQNJCQFTGFXCKZ9EZJAY"
                "WOTHFRQOHRIICSNZXKUULQJ9KRWKVORUTPACZPWJVKVEEZYJGIBBVFKGKQHN"
                "QQBFNLZEFKMWYTKNXWO9PEQLKPX";

  const char* key = iota_generateKey(seed.c_str(), 0, 2);
  int8_t* normalized = iota_normalize(bundleHash.c_str());

  auto sign0 = iota_sign(normalized, key);
  EXPECT_EQ(sign0, csign0);
  auto sign1 = iota_sign(normalized+27, key + IOTA_FRAGMENT_LENGTH);
  EXPECT_EQ(sign1, csign1);

  auto address = iota_generateAddress(seed.c_str(), 0, 2);

  const char* signatures[] = {sign0, sign1};

  EXPECT_TRUE(!iota_validateSignature(address, signatures, 2,  bundleHash.c_str()));
  free((void*) sign0);
  free((void*) sign1);
  free((void*) address);
  free((void*) key);
  free((void*) normalized);
}
