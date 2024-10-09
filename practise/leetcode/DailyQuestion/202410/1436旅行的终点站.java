class Solution {
    public String destCity(List<List<String>> paths) {
        Set<String> sa = new HashSet<>(paths.size());
        Set<String> sb = new HashSet<>();
        for (List<String> p : paths){
            String a = p.get(0);
            String b = p.get(1);
            sb.remove(a);
            if(!sa.contains(b)){
                sb.add(b);
            }
            sa.add(a);
        }
        return sb.iterator().next();
    }
}