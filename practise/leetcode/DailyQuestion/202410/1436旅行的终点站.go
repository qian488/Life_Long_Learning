func destCity(paths [][]string) string {
    sa := make(map[string]struct{}, len(paths))
    sb := map[string]struct{}{}
    for _, p := range paths {
        a, b := p[0], p[1]
        delete(sb, a) 
        if _, ok := sa[b]; !ok { 
            sb[b] = struct{}{}
        }
        sa[a] = struct{}{}
    }
    for b := range sb {
        return b
    }
    return ""
}
