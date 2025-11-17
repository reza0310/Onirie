import sys
import re

sancto_dict = {"#definir": "#define",
               "#dedef": "#undef",
               "#si": "#if",
               "#sidef": "#ifdef",
               "#sindef": "#ifndef",
               "#snsi": "#elif",
               "#sinn": "#else",
               "#finsi": "#endif",
               "#pragma": "#pragma", # C'est du grec mais on se veut exhaustifs
               "#attention": "#warning",
               "#erreur": "#error",
               "#inclure": "#include",
               "#ligne": "#line"
               }

def sanctinina(re):
    try:
        return sancto_dict[re]
    except:
        print(f"[PREPREPROCESSEUR] {re} n'est pas une macro invalide.", file=sys.stderr)
        sys.exit()

with open(sys.argv[-1], "r") as f:
    texte = f.read()

for x in re.findall("^ *(#[a-z]+)", texte, re.MULTILINE):
    texte = texte.replace(x, sanctinina(x), 1)
print(texte)
# Parce que ce petit batard ne veut pas marcher pour une raison que j'ignore:
# print(re.sub("^ *(#[a-z]+)", sanctinina, texte, re.MULTILINE))
