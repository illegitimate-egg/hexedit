{
  inputs.nixpkgs.url = "github:illegitimate-egg/hexedit";

  outputs = inputs:
    let
      system = "x86_64-linux";
      pkgs = inputs.nixpkgs.legacyPackages.${system};
    in
    {
      packages.${system}.default = pkgs.stdenv.mkDerivation {
        pname = "hexedit";
        version = "0.0.1";

        src = inputs.self;

        makeFlags = [ "PREFIX=${placeholder "out"}" ];

        buildInputs = with pkgs; [
          ncurses
        ];
      };
    };
}
