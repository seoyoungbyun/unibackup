/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/9.0.80
 * Generated at: 2023-12-12 05:01:58 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp.practice34;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class member3_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent,
                 org.apache.jasper.runtime.JspSourceImports {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  private static final java.util.Set<java.lang.String> _jspx_imports_packages;

  private static final java.util.Set<java.lang.String> _jspx_imports_classes;

  static {
    _jspx_imports_packages = new java.util.HashSet<>();
    _jspx_imports_packages.add("javax.servlet");
    _jspx_imports_packages.add("javax.servlet.http");
    _jspx_imports_packages.add("javax.servlet.jsp");
    _jspx_imports_classes = null;
  }

  private volatile javax.el.ExpressionFactory _el_expressionfactory;
  private volatile org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public java.util.Set<java.lang.String> getPackageImports() {
    return _jspx_imports_packages;
  }

  public java.util.Set<java.lang.String> getClassImports() {
    return _jspx_imports_classes;
  }

  public javax.el.ExpressionFactory _jsp_getExpressionFactory() {
    if (_el_expressionfactory == null) {
      synchronized (this) {
        if (_el_expressionfactory == null) {
          _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
        }
      }
    }
    return _el_expressionfactory;
  }

  public org.apache.tomcat.InstanceManager _jsp_getInstanceManager() {
    if (_jsp_instancemanager == null) {
      synchronized (this) {
        if (_jsp_instancemanager == null) {
          _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
        }
      }
    }
    return _jsp_instancemanager;
  }

  public void _jspInit() {
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
      throws java.io.IOException, javax.servlet.ServletException {

    if (!javax.servlet.DispatcherType.ERROR.equals(request.getDispatcherType())) {
      final java.lang.String _jspx_method = request.getMethod();
      if ("OPTIONS".equals(_jspx_method)) {
        response.setHeader("Allow","GET, HEAD, POST, OPTIONS");
        return;
      }
      if (!"GET".equals(_jspx_method) && !"POST".equals(_jspx_method) && !"HEAD".equals(_jspx_method)) {
        response.setHeader("Allow","GET, HEAD, POST, OPTIONS");
        response.sendError(HttpServletResponse.SC_METHOD_NOT_ALLOWED, "JSP들은 오직 GET, POST 또는 HEAD 메소드만을 허용합니다. Jasper는 OPTIONS 메소드 또한 허용합니다.");
        return;
      }
    }

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html; charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write('\r');
      out.write('\n');
      out.write("\r\n");
      out.write("\r\n");
 request.setCharacterEncoding("UTF-8"); 
      out.write("\r\n");
      out.write("<!DOCTYPE html>\r\n");
      out.write("<html>\r\n");
      out.write("<head>\r\n");
      out.write("<meta charset=\"UTF-8\">\r\n");
      out.write("<title>회원 가입</title>\r\n");
      out.write("<style>\r\n");
      out.write("        table{\r\n");
      out.write("            border-collapse: collapse;\r\n");
      out.write("        }\r\n");
      out.write("        table, th, td{\r\n");
      out.write("            border: 1px solid black;\r\n");
      out.write("        }\r\n");
      out.write("        th {\r\n");
      out.write("            background-color: #ececec;\r\n");
      out.write("            text-align: center;\r\n");
      out.write("            font-weight: bold;\r\n");
      out.write("            width: 70px;\r\n");
      out.write("        }\r\n");
      out.write("        textarea{\r\n");
      out.write("            width: 98%;\r\n");
      out.write("            height: 70px;\r\n");
      out.write("        }\r\n");
      out.write("        .len {\r\n");
      out.write("            width: 530px;\r\n");
      out.write("        }\r\n");
      out.write("        #title {\r\n");
      out.write("            width: 98%;\r\n");
      out.write("        }\r\n");
      out.write("    </style>\r\n");
      out.write("</head>\r\n");
      out.write("<body>\r\n");
      out.write("    <div align = \"center\">\r\n");
      out.write("        <img src=\"pic/eclass_title.jpg\" id = \"title\">\r\n");
      out.write("    </div>\r\n");
      out.write("    <div align = \"center\">\r\n");
      out.write("        <form method = \"post\" action = \"practice34.jsp\">\r\n");
      out.write("            <table>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th colspan = \"2\" class = \"len\">회원 가입</th>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">아이디</th>\r\n");
      out.write("                    <td>\r\n");
      out.write("                        <input type = text name = id>\r\n");
      out.write("                        <input type = image src = \"pic/check.gif\" style = \"vertical-align: middle\">\r\n");
      out.write("                    </td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">패스워드</th>\r\n");
      out.write("                    <td><input type = password name=pw></td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">성별</th>\r\n");
      out.write("                    <td>\r\n");
      out.write("                        <input type = radio name = gender value = \"남성\">남\r\n");
      out.write("                        <input type = radio name = gender value = \"여성\" checked>여\r\n");
      out.write("                    </td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">국적</th>\r\n");
      out.write("                    <td>\r\n");
      out.write("                        <input type = text value = \"대한민국\">\r\n");
      out.write("                        <input type = button value = \"국적변경\" disabled>\r\n");
      out.write("                    </td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">휴대폰</th>\r\n");
      out.write("                    <td>\r\n");
      out.write("                        <select name = phone1>\r\n");
      out.write("                            <option value = \"010\" selected>010</option>\r\n");
      out.write("                            <option value = \"011\">011</option>\r\n");
      out.write("                            <option value = \"017\">017</option>\r\n");
      out.write("                            <option value = \"070\">070</option>\r\n");
      out.write("                        </select>\r\n");
      out.write("                        -\r\n");
      out.write("                        <input type = tel name = phone2 size = 5px maxlength = \"4\">\r\n");
      out.write("                        -\r\n");
      out.write("                        <input type = tel name = phone3 size = 5px maxlength = \"4\">\r\n");
      out.write("                    </td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">이메일</th>\r\n");
      out.write("                    <td>\r\n");
      out.write("                        <input type = text name=email size = 40px style = \"width: 300px;\">\r\n");
      out.write("                    </td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">생일</th>\r\n");
      out.write("                    <td>\r\n");
      out.write("                        <input type = date name=birth>\r\n");
      out.write("                    </td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">관심분야</th>\r\n");
      out.write("                    <td>\r\n");
      out.write("                        <input type = checkbox name = hobby value = \"뉴스\">뉴스\r\n");
      out.write("                        <input type = checkbox name = hobby value = \"맛집\" checked>맛집\r\n");
      out.write("                        <input type = checkbox name = hobby value = \"책\">책\r\n");
      out.write("                        <input type = checkbox name = hobby value = \"영화\">영화\r\n");
      out.write("                        <input type = checkbox name = hobby value = \"여행\">여행\r\n");
      out.write("                    </td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">가입인사</th>\r\n");
      out.write("                    <td>\r\n");
      out.write("                        <textarea name=memo>회원들에게 간단한 가입인사를 남겨주세요</textarea>\r\n");
      out.write("                    </td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th class = \"gray\">증명사진</th>\r\n");
      out.write("                    <td><input type = file></td>\r\n");
      out.write("                </tr>\r\n");
      out.write("                <tr>\r\n");
      out.write("                    <th colspan = \"2\" class = \"len\">\r\n");
      out.write("                        <input type = \"submit\" value = \"가입하기\">\r\n");
      out.write("                        <input type = reset value = \"다시작성\">\r\n");
      out.write("                    </th>\r\n");
      out.write("                </tr>\r\n");
      out.write("            </table>\r\n");
      out.write("        </form>\r\n");
      out.write("    </div>\r\n");
      out.write("</body>\r\n");
      out.write("</html>");
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try {
            if (response.isCommitted()) {
              out.flush();
            } else {
              out.clearBuffer();
            }
          } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
