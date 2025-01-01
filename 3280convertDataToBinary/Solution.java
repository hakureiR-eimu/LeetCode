class Solution {
    public String convertDateToBinary(String date) {
        String[] dates = date.split("-");
        String year = Integer.toBinaryString(Integer.parseInt(dates[0]));
        String month = Integer.toBinaryString(Integer.parseInt(dates[1]));
        String day = Integer.toBinaryString(Integer.parseInt(dates[2]));
        return String.join("-", year, month, day);
    }
}