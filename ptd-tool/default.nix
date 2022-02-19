{ buildGoApplication
, fetchurl
, jq
, lib
, unzip
}:
buildGoApplication rec {
  pname = "ptd-tool";
  version = "8598cd75c3df84df973675402e5b7cc217552cdc";
  buildInputs = [ jq ];
  nativeBuildInputs = [ unzip ];
  src = fetchurl {
    url = "https://github.com/d-housekeeper/ptd-tool-orig/archive/${version}.zip";
    sha256 = "04wcdjj4690qa07kcpv65brgjkkvizj1idlb2d2p60b794g0rwrn";
  };
  modules = ./gomod2nix.toml;
  postBuild = ''
    mkdir -p $out/bin/
    cp ./generate-md-assets.sh $out/bin/
    cp -R ./assets/ $out/bin/assets/
  '';
}
