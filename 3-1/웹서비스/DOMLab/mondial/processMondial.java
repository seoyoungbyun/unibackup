package mondial;

import javax.xml.parsers.*;

import org.w3c.dom.*;

import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;

import java.io.*;
import java.text.NumberFormat;

public class processMondial {
	static final String inputFile = "mondial/mondial.xml";  // 나중에 "mondial/mondial.xml"로 변경해서 테스트 
	static final String outputFile = "mondial/result.xml";
	
	// 대륙별 인구 계산 및 출력을 위해 대륙 이름들을 저장한 배열 정의
    static final String continent[] = new String[] { "Africa", "America", "Asia", "Australia", "Europe" };
    
    static long pop[] = new long[5];  // 각 대륙의 인구 값을 저장할 배열 선언(대륙의 순서는 위 배열과 동일)
 
	public static void main(String[] args) throws Exception {
		// DOM 파서 생성
		DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
		factory.setIgnoringElementContentWhitespace(true);
		DocumentBuilder builder = factory.newDocumentBuilder();

		// XML 문서 파싱하기
		Document document = builder.parse(inputFile);

		Element mondial = document.getDocumentElement();
		
		// 대륙별 인구를 계산 및 출력 (3번)
		computePopulationsOfContinents(mondial);					
		
		// 종교별 신자 수를 계산 및 출력 (4번)
		// computeBelieversOfReligions(mondial);	
				
		// 국가별 정보 검색 및 출력 (1번)
		processCountries1(mondial);	
		
		// 국가별 정보 검색 및 DOM 트리 수정 (2번)
		processCountries2(mondial);	
		
		// 처리 결과 출력을 위한 변환기 생성
		TransformerFactory tf = TransformerFactory.newInstance();
		Transformer transformer = tf.newTransformer();

		// 출력 포맷 설정: XML 선언과 문서 유형 선언 내용 설정하기
		transformer.setOutputProperty(OutputKeys.ENCODING, "utf-8");
		// transformer.setOutputProperty(OutputKeys.DOCTYPE_SYSTEM,
		// "mondial.dtd");
		transformer.setOutputProperty(OutputKeys.INDENT, "yes");
		transformer.setOutputProperty("{http://xml.apache.org/xslt}indent-amount", "2");
		
		// DOMSource 객체 생성
		DOMSource source = new DOMSource(document);

		// StreamResult 객체 생성
		StreamResult result = new StreamResult(new File(outputFile));

		// 파일로 저장하기
		transformer.transform(source, result);
		
		System.out.println();
		System.out.println(outputFile + "로 저장되었습니다.");
	}

	public static void processCountries1(Element mondial) {
		for (Node ch = mondial.getFirstChild(); ch != null; ch = ch.getNextSibling()) {
			if (ch.getNodeName().equals("country")) {
				//country노드를 찾아 자식노드인 name노드를 가져와서 값을 출력한다
				Node name = ch.getFirstChild();
				String countryName = name.getFirstChild().getNodeValue();
				System.out.println(countryName);
				//country 엘리먼트의 속성인 area의 값을 가져와서 출력한다
				String area = ((Element)ch).getAttribute("area");
				System.out.println("면적: " + area);
				//name노드의 형제노드인 population노드를 가져와 갑을 출력한다
				Node pop = name.getNextSibling();
				String population = pop.getFirstChild().getNodeValue();
				System.out.println("인구: " + population);
				//country노드의 속성인 capital을 가져와 값이 null이 아닌지 검사하고 id값이 capital의 값과 엘리먼트를 찾아 그 엘리먼트의 자식 값(text node)를 출력한다
				String capitalId = ((Element)ch).getAttribute("capital");
				if (!capitalId.isEmpty()) {
					Element cap = ch.getOwnerDocument().getElementById(capitalId);
					Node capName = cap.getFirstChild();
					String capitalName = capName.getFirstChild().getNodeValue();
					System.out.println("수도의 이름: " + capitalName);
					System.out.println();
				}
				
			}
		}
		
	} 
	
	public static void processCountries2(Element mondial) {
		NodeList list = mondial.getElementsByTagName("country");
		for (int i = 0; i < list.getLength(); i++) {
			Element country = (Element)(list.item(i));
			
			Node name = country.getFirstChild();
			Node pop = name.getNextSibling();
			//해당 country의 car code값을 구해 code 엘리먼트를 만들고 pop엘리먼트 앞에 삽입한다.
			String carCode = ((Element)country).getAttribute("car_code");
			Element code = country.getOwnerDocument().createElement("code");
			Text tCode = country.getOwnerDocument().createTextNode(carCode);
			code.appendChild(tCode);	
			country.insertBefore(code, pop);
			
			String capitalId = ((Element)country).getAttribute("capital");
			if (!capitalId.isEmpty()) {
				//country의 capital속성값과 같은 id값을 가진 엘리먼트를 찾고(수도를 찾아), country의 population 이후의 자식 엘리먼트를 모두 삭제한다. 이후 찾아놓은 수도 엘리먼트를 자식 엘리먼트로 추가한다. 
				Element cap = country.getOwnerDocument().getElementById(capitalId);
				if (cap != null) {
					Node parent = cap.getParentNode();
					Node city = parent.removeChild(cap);
					NodeList nodeList = country.getChildNodes();
					while (nodeList.getLength() > 3) {
						country.removeChild(nodeList.item(3));
					}
					country.appendChild(city);
					//수도 엘리먼트의 속성을 제거한다.
					((Element) city).removeAttribute("is_country_cap");
					((Element) city).removeAttribute("is_state_cap");
					((Element) city).removeAttribute("country");
					((Element) city).removeAttribute("province");
				}
			}
			//coutnry의 id를 제외한 속성을 모두 제거한다.
			NamedNodeMap attrMap = country.getAttributes();
			int len = attrMap.getLength();
		    for (int j = 0; j < len; j++) {
		        Node attribute = attrMap.item(0);
		        country.removeAttribute(attribute.getNodeName());
		    } 
		}
		//coutry를 제외한 형제 엘리먼트는 모두 삭제한다.
		int len = list.getLength();
		NodeList child = mondial.getChildNodes();
		while (child.getLength() > len) {
			mondial.removeChild(child.item(len));
		}
	}		
		
	
	public static void computePopulationsOfContinents(Node mondial) {
		NodeList list = mondial.getOwnerDocument().getElementsByTagName("country");
        for (int i = 0; i < list.getLength(); i++) {
            Element country = (Element) (list.item(i));   
            //인구 노드 가져오기
			NodeList pop = country.getElementsByTagName("population");
			
			double max = 0;
			String continent = "";
			if (pop.getLength() != 0) {
				//인구 노드의 값을 sPopulation에 저장해서 Long.parseLong으로 String의 인구를 long형으로 바꾸기
				String sPopulation = pop.item(0).getFirstChild().getNodeValue();
				long population = Long.parseLong(sPopulation);
				//encompassed라는 노드를 찾을때까지 for문을 반복하고 찾으면 percentage노드의 값을 max값과 비교해 max값이 percentage값보다 작으면 max에 percentage값 대입 후 continent도 해당하는 대륙의 이름으로 바꿈
				for (Node ch = country.getFirstChild(); ch != null; ch = ch.getNextSibling()) {
					if (ch.getNodeName().equals("encompassed")) {
						String sPercent = ((Element) ch).getAttribute("percentage");
						double percent = Double.parseDouble(sPercent);
						if (max < percent) {
							max = percent;
							continent = ((Element) ch).getAttribute("continent");
						}
					}
				}
				//continent에 저장된 값에 따라 pop배열에 population에 저장된 값을 더해준다
				switch(continent) {
					case "africa":
						processMondial.pop[0] += population;
						break;
					case "america":
						processMondial.pop[1] += population;
						break;
					case "asia":
						processMondial.pop[2] += population;
						break;
					case "australia":
						processMondial.pop[3] += population;
						break;
					case "europe":
						processMondial.pop[4] += population;
						break;
					}
			}
        }
		// 계산된 각 대륙의 인구를 출력
		printPopulationsOfContinents();
	}

	public static void printPopulationsOfContinents() {
		System.out.println("Populations of the Continents");
		System.out.println("------------------------------");
		NumberFormat formatter = NumberFormat.getInstance();
		
		long sum = 0;
		
		System.out.println(processMondial.continent[4] + "의 인구: " + formatter.format(processMondial.pop[4]));
		sum += processMondial.pop[4];
		System.out.println(processMondial.continent[2] + "의 인구: " + formatter.format(processMondial.pop[2]));
		sum += processMondial.pop[2];
		System.out.println(processMondial.continent[1] + "의 인구: " + formatter.format(processMondial.pop[1]));
		sum += processMondial.pop[1];
		System.out.println(processMondial.continent[0] + "의 인구: " + formatter.format(processMondial.pop[0]));
		sum += processMondial.pop[0];
		System.out.println(processMondial.continent[3] + "의 인구: " + formatter.format(processMondial.pop[3]));
		sum += processMondial.pop[3];
		
		System.out.println("------------------------------");
		System.out.println("합계: " + sum + "명\n");
		
	}
	
}