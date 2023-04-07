{
  description = "A C based hexeditor";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs =
    { self
    , nixpkgs
    }:

    let
      overlays = [
        (self: super: {
          nodejs = super.nodejs-18_x;
        })
    ];

      allSystems = [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];

      forAllSystems = f: nixpkgs.lib.genAttrs allSystems (system: f {
        pkgs = import nixpkgs { inherit overlays system; };
      });
    in
    {
      packages = forAllSystems ({ pkgs }: {
        default =
          let
            binName = "hexedit";
            cDependencies = with pkgs; [ ncurses ];
          in
          pkgs.stdenv.mkDerivation {
            name = "hexedit";
            src = self;
            
            makeFlags = [ "PREFIX=${placeholder "out"}" ];

            buildInputs = cDependencies;
          };
      });
    };
}
