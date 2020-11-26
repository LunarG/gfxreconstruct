def extract_doxygen_method_params(doxystr):
    """
    Given a doxygen string for a method, extract parameter descriptions
    """
    doxyVarDesc = {}
    doxyLines = doxystr.split("\n")
    lastParamDesc = ""
    for doxyLine in doxyLines:
        if " @param " in doxyLine or " \\param " in doxyLine:
            try:
                # Strip out the param
                doxyLine = doxyLine[doxyLine.find("param ") + 6 :]
                (var, desc) = doxyLine.split(" ", 1)
                doxyVarDesc[var] = desc.strip()
                lastParamDesc = var
            except:
                pass
        elif " @return " in doxyLine or " \return " in doxyLine:
            lastParamDesc = ""
            # not handled for now
        elif lastParamDesc:
            try:
                doxyLine = doxyLine.strip()
                if " " not in doxyLine:
                    lastParamDesc = ""
                    continue
                doxyLine = doxyLine[doxyLine.find(" ") + 1 :]
                doxyVarDesc[lastParamDesc] += " " + doxyLine
            except:
                pass

    return doxyVarDesc
